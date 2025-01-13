#ifndef _SONG_H_
#define _SONG_H_
/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define BUFFER_SIZE 2000
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef uint8_t queuedata_t; // Queuedata podria ser en principio 8 bits. Cambiarlo despues de ver que funciona

typedef struct _Song
{
  char *filename;
  char *path;
} song_t;

typedef struct _SongInfo
{
  char *title;
  char *artist;
  char *date;

} song_info_t;


song_t *newSong(const char *path, const char *filename);
void destroySong(song_t *song);

/*******************************************************************************
 ******************************************************************************/

#endif // _QUEUE_H_