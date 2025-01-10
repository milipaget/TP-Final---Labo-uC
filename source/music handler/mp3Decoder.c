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
#include "mp3Decoder.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "ff.h"
//#include "diskio.h"
//#include "fsl_sd_disk.h"
#include "sdmmc_config.h"
#include "fsl_sysmpu.h"
#include "MK64F12.h"
#include <mp3dec.h>
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define TAG_SIZE 128

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

// Helix data
static HMP3Decoder   	helixDecoder;       // Helix MP3 decoder instance
static MP3FrameInfo 	lastFrameInfo;      // MP3 frame info


// MP3 file data
static FIL 				mp3FileObject;		// MP3 file object
static uint32_t      	fileSize;          	// Size of the file used
static uint32_t      	remainingBytes;		// Encoded MP3 bytes remaining to be decoded
static bool          	fileIsOpened;       // true if there is an open file, false if is not
static uint32_t      	lastFrameLength;   	// Last frame length


// MP3-encoded buffer data
static uint8_t 		mp3FrameBuffer[NUMBER_BYTES_PER_FRAME] __attribute__((aligned(4)));
static int32_t    	mp3BufferOut;  // Index of the next element to be read (first element in buffer)
static int32_t     mp3BufferIn;   // Index of the next element to be loaded (after the last element in buffer)


// ID3 tag data
static bool hasID3;								// True if the file has valid ID3 tag
static char title[ID3_MAX_NUM_CHARS];         	// Title of the song
static char artist[ID3_MAX_NUM_CHARS];        	// Artist of the song
static char album[ID3_MAX_NUM_CHARS];         	// Album of the song
static char trackNum[ID3_MAX_NUM_CHARS];      	// Number of the track inside the album of the song
static char year[ID3_MAX_NUM_CHARS];          	// Year of the songs' album
typedef struct
{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    unsigned char genre;
} ID3Tag;

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


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


/******************************************************************************/
