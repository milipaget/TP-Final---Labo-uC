/***************************************************************************//**
  @file     gpio.h
  @brief    Simple GPIO Pin services, similar to Arduino
  @author   Nicolás Magliola
 ******************************************************************************/

#ifndef _GPIO_H_
#define _GPIO_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

// Ports
enum { PA, PB, PC, PD, PE };

// Convert port and number into pin ID
// Ex: PTB5  -> PORTNUM2PIN(PB,5)  -> 0x25
//     PTC22 -> PORTNUM2PIN(PC,22) -> 0x56
#define PORTNUM2PIN(p,n)    (((p)<<5) + (n))
#define PIN2PORT(p)         (((p)>>5) & 0x07)
#define PIN2NUM(p)          ((p) & 0x1F)
#define PORT2ADDR(x) ((PORT_Type*)(PORTA_BASE + (((x)<<12u) & 0x0000F000u)))
#define PORT2GPIOADDR(x) ((GPIO_Type*)(GPIOA_BASE + (((x) << 6u) & 0x000001C0u)))

// Modes
#ifndef INPUT
#define INPUT               0
#define OUTPUT              1
#define INPUT_PULLUP        2
#define INPUT_PULLDOWN      3
#define FILTER_ENABLE		4
#endif // INPUT




// Digital values
#ifndef LOW
#define LOW     0
#define HIGH    1
#endif // LOW

/***** BOARD defines **********************************************************/

// On Board User LEDs
#define PIN_LED_RED PORTNUM2PIN(PB, 22)   // PTE22
#define PIN_LED_GREEN PORTNUM2PIN(PE, 26) // PTE26
#define PIN_LED_BLUE PORTNUM2PIN(PB, 21)  // PTB21

#define LED_ACTIVE LOW
// Prueba 2, borrar

// On Board User Switches
#define PIN_SW2 PORTNUM2PIN(PC, 6) // PTC6
#define PIN_SW3 PORTNUM2PIN(PA, 4) // PTA4

#define SW_ACTIVE LOW              // ???
#define SW_INPUT_TYPE INPUT_PULLUP // ???

/*******************************************************************************
 ******************************************************************************/


// IRQ modes
enum {
    GPIO_IRQ_MODE_DISABLE = 0,
    GPIO_IRQ_MODE_RISING_EDGE = 0b1001,
    GPIO_IRQ_MODE_FALLING_EDGE = 0b1010,
    GPIO_IRQ_MODE_BOTH_EDGES = 0b1011,

    GPIO_IRQ_CANT_MODES
};


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef uint8_t pin_t;

typedef void (*pinIrqFun_t)(void);


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Configures the specified pin to behave either as an input or an output
 * @param pin the pin whose mode you wish to set (according PORTNUM2PIN)
 * @param mode INPUT, OUTPUT, INPUT_PULLUP or INPUT_PULLDOWN.
 */
void gpioMode (pin_t pin, uint8_t mode);

/**
 * @brief Configures how the pin reacts when an IRQ event ocurrs
 * @param pin the pin whose IRQ mode you wish to set (according PORTNUM2PIN)
 * @param irqMode disable, risingEdge, fallingEdge or bothEdges
 * @param irqFun function to call on pin event
 * @return Registration succeed
 */
bool gpioIRQ (pin_t pin, uint8_t irqMode, pinIrqFun_t irqFun);

/**
 * @brief Write a HIGH or a LOW value to a digital pin
 * @param pin the pin to write (according PORTNUM2PIN)
 * @param val Desired value (HIGH or LOW)
 */
void gpioWrite (pin_t pin, bool value);

/**
 * @brief Toggle the value of a digital pin (HIGH<->LOW)
 * @param pin the pin to toggle (according PORTNUM2PIN)
 */
void gpioToggle (pin_t pin);

/**
 * @brief Reads the value from a specified digital pin, either HIGH or LOW.
 * @param pin the pin to read (according PORTNUM2PIN)
 * @return HIGH or LOW
 */
bool gpioRead (pin_t pin);


/*******************************************************************************
 ******************************************************************************/

#endif // _GPIO_H_
