/***************************************************************************//**
  @file     mp3Config.c
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
#include "mp3Config.h"

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void initMp3Config(void){
    mp3ConfigVariables.volume = MAX_VOLUME/2; //uint8_t
    mp3ConfigVariables.songPointer = 0; //uint8_t
    mp3ConfigVariables.isPlaying = false;
    mp3ConfigVariables.isOn = true;
    mp3ConfigVariables.errorType = NONE; //uint8_t
    mp3ConfigVariables.filterType = NONE; //uint8_t
}

/******************************************************************************/
