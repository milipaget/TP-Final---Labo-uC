/***************************************************************************//**
  @file     musicHandler.h
  @brief    Handles songs, its reproduction and makes space for storage.
  @author   Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
 ******************************************************************************/

#ifndef _MUSICHANDLER_H_
#define _MUSICHANDLER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef struct _Song{
  char *filename;
  char *path;
} song_t;

typedef struct _SongInfo{
  char *title;
  char *artist;
  char *date;
} song_info_t;

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
song_t * newSong(const char *path, const char *filename);
void destroySong(song_t *song);


/*******************************************************************************
 ******************************************************************************/

#endif // _MUSICHANDLER_H_