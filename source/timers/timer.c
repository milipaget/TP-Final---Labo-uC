/***************************************************************************//**
  @file     timer.c
  @brief    Timer driver. Advance implementation
  @author   Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "timer.h"
#include "MK64F12.h"
#include "../../SDK/startup/hardware.h"
#include "../MCAL/gpio.h" 
#include "../pinout.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define REF_FREQ 1000U //1ms

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef struct {
	uint8_t state;
    tim_callback_t callback;
    uint32_t counter;	//Contador actual
	uint32_t time;	//Valor de tiempo
	uint8_t mode;
} timer_t;


/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
static timer_t timers[TIMERS_MAX_CANT];


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void timerInit(void){
    static bool yaInit = false;
	if(Systick_Config(__CORE_CLOCK__/REF_FREQ) == 0){
		NVIC_EnableIRQ(SysTick_IRQn);
		yaInit = true;
	}
	return yaInit;
}

uint8_t createTimer(uint32_t time, tim_callback_t callback, tim_modes_t mode){

	uint8_t tim_id = 0;
	bool found = false;

	while(tim_id < TIMERS_MAX_CANT && !found){
		if(timers[tim_id].state == TIM_STATE_FREE){
			timers[tim_id].mode = mode;
			timers[tim_id].state = TIM_STATE_SELECTED;
			timers[tim_id].time = time;
			timers[tim_id].callback = callback;
			resetTimer_SYS(tim_id);
			found = true;
		}
		else{
			tim_id++;
		}
	}

	return tim_id;
}

void setTimerCallback(uint8_t tim_id, tim_callback_t callback){
	timers[tim_id].callback = callback;
}

void setTimerTime(uint8_t tim_id, uint32_t time){
	timers[tim_id].time = time;
}

void setTimerMode(uint8_t tim_id, tim_modes_t mode){
	timers[tim_id].mode = mode;
}

void destroyTimer(uint8_t tim_id){
	timers[tim_id].counter = 0;
	timers[tim_id].state = TIM_STATE_FREE;
}

void resetTimer(uint8_t tim_id){
	timers[tim_id].counter = 0;
}

void startTimer(uint8_t tim_id){
	timers[tim_id].counter = 0;
	if (timers[tim_id].state != TIM_STATE_FREE)
		timers[tim_id].state = TIM_STATE_RUNNING;
}

void stopTimer(uint8_t tim_id){
	if (timers[tim_id].state != TIM_STATE_FREE)
		timers[tim_id].state = TIM_STATE_RUNNING;
	timers[tim_id].counter = 0;
}

uint32_t getTime(uint8_t tim_id){
	return timers[tim_id].counter;
}

uint8_t getTimerState(uint8_t tim_id){
	return timers[tim_id].state;
}

/******************************************************************************/
