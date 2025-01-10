/***************************************************************************//**
  @file     timer.h
  @brief    Timer driver. Advance implementation
  @author   Nicolás Magliola
 ******************************************************************************/

#ifndef _TIMER_H_
#define _TIMER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define TIMER_TICK_MS       1
#define TIMER_MS2TICKS(ms)  ((ms)/TIMER_TICK_MS)

#define TIMER_TICKS_PER_MS	10
#define TIMER_MS_2_TICKS(ms)	((ms)*TIMER_TICKS_PER_MS)

#define TIMERS_MAX_CANT     16
#define TIMER_INVALID_ID    255


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

// Timer Modes
typedef enum { TIM_MODE_SINGLESHOT, TIM_MODE_PERIODIC, CANT_TIM_MODES } tim_modes_t;

// Timer States
enum {TIM_STATE_FREE, TIM_STATE_SELECTED, TIM_STATE_RUNNING};

// Timer alias
typedef void (*tim_callback_t)(void);


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Initialice timer and corresponding peripheral
 */
void timerInit(void);

/**
 * @brief Create a new timer
 * @param id ID of the timer to start
 * @param time time until timer expires
 * @param mode SINGLESHOT or PERIODIC
 * @param callback Function to be call when timer expires
 * @return uint8_t timer ID
 */
uint8_t createTimer(uint32_t time, tim_callback_t callback, tim_modes_t mode);

/**
 * @brief Start running a timer
 * @param tim_id timer ID
 */
void timerStart(uint8_t tim_id);

/**
 * @brief Finish to run a timer
 * @param tim_id ID of the timer to stop
 */
void timerStop(uint8_t tim_id);

/**
 * @brief Set timer callback
 * @param tim_id ID of the timer
 * @param callback callback del timer
 */
void setTimerCallback(uint8_t tim_id, tim_callback_t callback);

/**
 * @brief Set timer time
 * @param tim_id ID of the timer to stop
 * @param time time del timer
 */
void setTimerTime(uint8_t tim_id, uint32_t time);

/**
 * @brief Set timer mode
 * @param tim_id ID of the timer
 * @param mode mode del timer
 */
void setTimerMode(uint8_t tim_id, tim_modes_t mode);

/**
 * @brief Destroy timer
 * @param id ID of the timer
 */
void destroyTimer(uint8_t tim_id);

/**
 * @brief Restart timer
 * @param id ID of the timer
 */
void resetTimer(uint8_t tim_id);

/**
 * @brief Get timer time
 * @param id ID of the timer
 * @return uint32_t timer time
 */
uint32_t getTime(uint8_t tim_id);

/**
 * @brief Get timer state
 * @param id ID of the timer
 * @return uint8_t timer state
 */
uint8_t getTimerState(uint8_t tim_id);

/*******************************************************************************
 ******************************************************************************/

#endif // _TIMER_H_
