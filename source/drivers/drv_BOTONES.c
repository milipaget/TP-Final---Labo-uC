/*******************************************************************************
   @file    drv_BOTONES.c
   @brief   Driver que inicializa y maneja el uso de los botones
   @author  Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
********************************************************************************/

/********************************************************************************
*                           INCLUDE HEADER FILES                                *
*********************************************************************************/
#include "drv_BOTONES.h"

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
/**
 * @brief Esta función se encarga de inicializar el botón de cambiar el filtro.
 * @return void
 */
void initChangeFilterButton (void);

/**
 * @brief Esta función se encarga de inicializar el botón de pasar a la canción anterior.
 * @return void
 */
void initPrevSongButton (void);

/**
 * @brief Esta función se encarga de inicializar el botón de pasar a la siguiente canción.
 * @return void
 */
void initNextSongButton (void);

/**
 * @brief Esta función se encarga de inicializar el botón de encendido o apagado.
 * @return void
 */
void initOnOffButton (void);

/**
 * @brief Esta función se encarga de inicializar el botón de encendido o apagado.
 * @return void
 */
void changeFilterButtonISR(void);

/**
 * @brief Esta función se encarga de inicializar el botón de encendido o apagado.
 * @return void
 */
void prevSongButtonISR(void);

/**
 * @brief Esta función se encarga de inicializar el botón de encendido o apagado.
 * @return void
 */
void nextSongButtonISR(void);

/**
 * @brief Esta función se encarga de inicializar el botón de encendido o apagado.
 * @return void
 */
void onOffButtonISR(void);

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH LOCAL SCOPE
 ******************************************************************************/
uint8_t buttonTimer = 0;

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH GLOBAL SCOPE
 ******************************************************************************/
void initButtons(void){
    initChangeFilterButton();
    initNextSongButton();
    initOnOffButton();
    initPrevSongButton();
    //buttonTimer = createTimer_SYS(100, buttonMgmtISR, SYS_PERIODIC);
	//startTimer_SYS(buttonTimer);
}

void buttonMgmtISR(void){
	changeFilterButtonISR();
	prevSongButtonISR();
	nextSongButtonISR();
	onOffButtonISR();
}

/*******************************************************************************
 * FUNCTION DEFINITIONS WITH LOCAL SCOPE
 ******************************************************************************/
void initChangeFilterButton (void){
    gpioMode(CHANGE_FILTER_BUTTON_PIN, INPUT);
}

void initPrevSongButton (void){
    gpioMode(PREV_BUTTON_PIN, INPUT);
}

void initNextSongButton (void){
    gpioMode(NEXT_BUTTON_PIN, INPUT);
}

void initOnOffButton (void){
    gpioMode(ON_OFF_BUTTON_PIN, INPUT);
}

void changeFilterButtonISR(void){
    static bool lastState = HIGH;
	bool state = gpioRead(CHANGE_FILTER_BUTTON_PIN);

	if(lastState == HIGH && state == LOW){

		lastState = state;

		putEvent(changeFilter);
	}
	else if (lastState == LOW && state == HIGH){

		lastState = state;
	}
}

void prevSongButtonISR(void){
    static bool lastState = HIGH;
	bool state = gpioRead(PREV_BUTTON_PIN);

	if(lastState == HIGH && state == LOW){

		lastState = state;

		putEvent(prevSong);
	}
	else if (lastState == LOW && state == HIGH){

		lastState = state;
	}
}

void nextSongButtonISR(void){
    static bool lastState = HIGH;
	bool state = gpioRead(NEXT_BUTTON_PIN);

	if(lastState == HIGH && state == LOW){

		lastState = state;

		putEvent(nextSong);
	}
	else if (lastState == LOW && state == HIGH){

		lastState = state;
	}
}

void onOffButtonISR(void){
    static bool lastState = HIGH;
	bool state = gpioRead(ON_OFF_BUTTON_PIN);

	if(lastState == HIGH && state == LOW){

		lastState = state;

		putEvent(onOff);
	}
	else if (lastState == LOW && state == HIGH){

		lastState = state;
	}
}

/*******************************************************************************
 ******************************************************************************/
