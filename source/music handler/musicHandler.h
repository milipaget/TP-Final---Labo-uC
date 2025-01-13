/***************************************************************************//**
  @file     musicHandler.h
  @brief    Manages playing songs.
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
typedef enum _Player_MSG
{
  Playing,
  Paused,
  Stoped
} player_msg_t;

typedef struct _Player
{
  song_node_t *currSong;
  float volume;

} player_t;

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
bool playPlayer();
bool stopPlayer();
bool pausePlayer();
bool nextSong();
bool prevSong();
void adjustVolume(float vol);
char *getCurrentSongName();

song_node_t *getSongList();
bool selectSong(song_node_t *song);

player_msg_t updatePlayer();

bool playerInit();

/*******************************************************************************
 ******************************************************************************/

#endif // _MUSICHANDLER_H_