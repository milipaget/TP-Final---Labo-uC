/*******************************************************************************
   @file    mp3Config.h
   @brief   Contiene las variables y constantes necesarias para el funcionamiento
            del mp3
   @author  Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
  ******************************************************************************/

#ifndef _MP3CONFIG_H_
#define _MP3CONFIG_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define EQTYPE 4
#define MAX_VOLUME 30

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
//const char *eqTypes[EQTYPE] = {"None", "Rock", "Pop", "Bass"};
enum filterTypes{NONE, ROCK, POP, BASS};
enum errorTypes{NONE, NO_SD, NO_SONGS};

struct mp3config_variables
{
	int volume = MAX_VOLUME/2; //uint8_t
    int songPointer = 0; //uint8_t
    bool isPlaying = false;
    bool isOn = true;
    int errorType = NONE; //uint8_t
    int filterType = NONE; //uint8_t
};

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
static int songNum = 0;//Esta variable se actualiza cuando se inserta la SD card (uint8_t???)
static mp3config_variables mp3ConfigVariables;
//mp3config_variables* pointer2config = mp3ConfigVariables

/*******************************************************************************
 ******************************************************************************/

#endif // _MP3CONFIG_H_


