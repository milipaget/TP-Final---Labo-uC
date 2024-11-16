/***************************************************************************/ /**
   @file     vumeter.h
   @brief    vumeter driver
   @author  Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include "vumeter.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define ON (true)
#define OFF (false)

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static const float blinkTime = 500000; // 0.5s

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static bool state = ON;
static bar bandSelected = 0;

/*******************************************************************************
 *******************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void initVumeter()
{

	color_t aux;

	initLEDMatrix();

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			switch (j)
			{
			case 0:
			case 1:
			case 2:
				aux.hex = YELLOW;
				changeColor(j, i, aux);
				break;

			case 3:
			case 4:
			case 5:
				aux.hex = RED;
				changeColor(j, i, aux);
				break;

			case 6:
			case 7:
				aux.hex = PURPLE;
				changeColor(j, i, aux);
				break;
			}
		}
	}

	adjustBrightness(2);
	vumeterOn();
}

void vumeterOn()
{
	state = ON;
}

void vumeterOff()
{
	state = OFF;
}

void turnOffVumeter(void)
{
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			turnOff(i, j);
		}
	}
	return;
}

void adjustBrightness(uint8_t bright)
{
	changeBrightness(bright);
}

void setLevel(uint8_t level)
{
	if (level < 0)
	{
		level = 0;
	}
	else if (level > MAXLEVEL)
	{
		level = MAXLEVEL;
	}

	for (int i = 0; i < COLS; i++)
	{
		if (i < level)
		{
			turnOn(i, bandSelected);
		}
		else
		{
			turnOff(i, bandSelected);
		}
	}
}

void selectBar(bar barID)
{

	if (barID < b34Hz)
	{
		barID = b34Hz;
	}
	else if (barID > b14K2Hz)
	{
		barID = b14K2Hz;
	}

	// stopBlinkBar(bandSelected);
	// turnOnBar(bandSelected);
	bandSelected = barID;
	// blinkBar(bandSelected, blinkTime);
}

/*******************************************************************************
 *******************************************************************************
						LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
