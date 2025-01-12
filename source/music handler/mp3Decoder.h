/***************************************************************************//**
  @file     mp3Decoder.h
  @brief    mp3 Decoder
  @author   Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
 ******************************************************************************/

#ifndef _MP3DECODER_H_
#define _MP3DECODER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "songList.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define DEC_BUFFER_SIZE 1152

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Get timer state
 * @param id ID of the timer
 * @return uint8_t timer state
 */
bool MP3DecInit(void);

int MP3SelectSong(song_t *song);

int MP3DecDecode(int16_t *buffer, uint32_t *samprate);

/*******************************************************************************
 ******************************************************************************/

#endif // _MP3DECODER_H_