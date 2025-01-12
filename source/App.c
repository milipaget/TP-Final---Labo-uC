/***************************************************************************//**
  @file     App.c
  @brief    Application functions
  @author   Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
  ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "hardware.h"

//#include "player.h"

#include "fsm.h"
#include "fsmtable.h" /*FSM Table*/

#include "MCAL/gpio.h"
//#include "protocols/I2C.h"
#include "MCAL/board.h"
#include "mp3Config.h"
//#include "button.h"
//#include "encoder.h"
//#include "display.h"
//#include "vumeter/vumeter.h"
//#include "equalizer/equalizer.h"
//#include "deepSleep.h"
#include "eventos/eventQueue.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
STATE *p2state = NULL; // puntero al estado

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/* Función que se llama 1 vez, al comienzo del programa */
void App_Init(void)
{
	//playerInit();
	//initTimer_SYS();

	//I2CInit();

	//initButtons();
	//initEncoder();
	//initDisplay();
	//initVumeter();
	//initEqualizer();

	//deepSleep_init();
	initMp3Config();

	p2state = FSM_GetInitState(); // Inicializo la FSM con el estado inicial
}

/* Función que se llama constantemente en un ciclo infinito */
void App_Run(void)
{
	static event_t nextEvent;

	nextEvent = getNextEvent();
	if (nextEvent != None)
	{
		p2state = fsm(p2state, nextEvent); 
	}
	//updatePlayer();
}

/*******************************************************************************
 *******************************************************************************
 LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/*******************************************************************************
 ******************************************************************************/
