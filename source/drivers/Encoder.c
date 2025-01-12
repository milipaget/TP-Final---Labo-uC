#include "encoder.h"        // :)
#include <hardware.h>
#include "..\timer.h"       // Para poder controlar los timers: crearlos y configurarlos...
#include "..\gpio.h"        // Configuración de los gpio: qué pin y en qué modo...
#include "..\pinout.h"      // Configuración relqacionada a la placa -> qué pines de qué puerto usa
#include <stdlib.h>         // :)
#include "..\Queue.h"
#include "../board/board.h"
#include "../eventos/eventQueue.h"     // Para poner el evento en la cola


/*
	En config.h: se define qué pin de qué puerto se usa para las entradas:
	#define ENCODER_OUT_A PORTNUM2PIN(PB, 2)
	#define ENCODER_OUT_B PORTNUM2PIN(PB, 3)

	Después esto se va a usar para configurar los gpio:
	gpioMode (pin_t pin, uint8_t mode); -> gpioMode(ENCODER_OUT_A, INPUT);
	gpioIRQ (pin_t pin, uint8_t irqMode, pinIrqFun_t irqFun); -> (gpioIRQ(ENCODER_OUT_A, GPIO_IRQ_MODE_FALLING_EDGE, &encoderACallback))
	En esta última se define que es una entrada y que la función que debe realizarse al estar esta interrupción es RCHA_CB (cuando se activa la señal)


    Si se detecta un giro se pone el evento en la cola         putEvent(EncoderLeft);  // Registrar evento de giro antihorario


    En eventQueue están definidos los eventos
        typedef enum event_type
    {
        None,
        EncoderLeft,
        EncoderRight,
        EncoderClick,
        ButtonCross,
        ButtonPoint,
        ButtonLine
    } event_t;


    El estado se usa después en la tabla de estados:
        STATE st_eq[] =
    {
        {EncoderLeft,st_eq,changeEqLeft},
        {EncoderRight,st_eq,changeEqRight},
        {ButtonLine,st_rep,goToRepFromEq},
        {EncoderClick, st_off, turnOff},
        {FIN_TABLA,st_eq,do_nothing}
    };

*/

// Estados activos para las señales del encoder
#define SWITCH_ACTIVE LOW  // Estado activo para el botón del encoder
#define ROTARY_ACTIVE LOW  // Estado activo para las señales del encoder

// Constantes de tiempo para el manejo del encoder
#define DEBOUNCE_DELAY 10  // Tiempo para evitar rebotes (en ms... se multiplica en función de time)
#define SWITCH_SAMPLING_TIME 10
#define DOUBLE_CLICK_TIME 350
#define ENCODER_EVENT_DELAY 100  // Tiempo para procesar eventos del encoder (en ms)
#define MAX_LONG_CLICK_TIME 10000
#define LONG_CLICK_TIME 2000

// Variable para ignorar entradas durante el tiempo de 
static bool ignoreRotaryInput = false;

// ID del temporizador asociado al encoder
static uint8_t rotaryTimerID;

// Declaración de funciones
static void encoderACallback(void);  // Callback para el canal A
static void encoderBCallback(void);  // Callback para el canal B
static void rebootEncoderDetection(void);  // Rehabilita detección tras temporizador

// Inicializa el encoder rotativo
bool initEncoder(void) {

    // Configurar pines del encoder como entradas
    gpioMode(ENCODER_OUT_A, INPUT);
    gpioMode(ENCODER_OUT_B, INPUT);

    // Asignar callbacks a las interrupciones de los pines
    if (gpioIRQ(ENCODER_OUT_A, GPIO_IRQ_MODE_FALLING_EDGE, &encoderACallback)) {
        return true; // Error al configurar interrupción
    }
    if (gpioIRQ(ENCODER_OUT_B, GPIO_IRQ_MODE_FALLING_EDGE, &encoderBCallback)) {
        return true; // Error al configurar interrupción
    }

    // Crear temporizador para manejar eventos del encoder: ONESHOT -> Al terminar este tiempo activa el encoder de nuevo
    rotaryTimerID = createTimer_SYS(ENCODER_EVENT_DELAY, &rebootEncoderDetection, ONESHOT);
    return false; // Inicialización exitosa
}

// Callback para el canal A del encoder
static void encoderACallback(void) {
    // Ignorar entrada si está bloqueada o el pin A no está activo
    if (ignoreRotaryInput || gpioRead(ENCODER_OUT_A) != ROTARY_ACTIVE) {
        return;
    }

    // Verificar estado del canal B para determinar el sentido -> Si gira en sentido antihorario B se prende antes que A
    if (gpioRead(RCHB_PIN)) {
        // Movimiento antihorario detectado
        putEvent(EncoderLeft);  // Registrar evento de giro antihorario
    }

    // Bloquear nuevas entradas y activar temporizador
    ignoreRotaryInput = true;
    startTimer_SYS(rotaryTimerID);  // Se detectó recién que se prendió el A, no me fijo por un ratito
}

// Callback para el canal B del encoder
static void encoderBCallback(void) {
    // Ignorar entrada si está bloqueada o el pin B no está activo
    if (ignoreRotaryInput || gpioRead(ENCODER_OUT_B) != ROTARY_ACTIVE) {
        return;
    }

    // Verificar estado del canal A para determinar el sentido -> Si gira en sentido horario A se prende antes que B
    if (gpioRead(ENCODER_OUT_A)) {
        // Movimiento horario detectado
        putEvent(EncoderRight);  // Registrar evento de giro horario
    }

    // Bloquear nuevas entradas y activar temporizador
    ignoreRotaryInput = true;
    startTimer_SYS(rotaryTimerID); // Se detectó recién que se prendió el B, no me fijo por un ratito
}

// Rehabilita la detección de entradas del encoder
static void rebootEncoderDetection(void) {
    ignoreRotaryInput = false; // Permitir nuevas interrupciones :) 
}
