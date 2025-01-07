/*******************************************************************************
  @file     equalizer.h
  @brief    Equalizer por song effects Header.
  @author   Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
 ******************************************************************************/
#ifndef EQUALIZER_H
#define EQUALIZER_H

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "arm_math.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/* Length of the overall data FRAME */
#define FRAME_SIZE (1152U)

/* Block size for the underlying processing */
#define BLOCKSIZE (36)

/* Total number of blocks to run */
#define NUMBER_OF_BLOCKS (FRAME_SIZE/BLOCKSIZE)

/* Number of 2nd order Biquad stages per filter */
#define NUMBER_OF_STAGES (2)

/*Number of coefficients that describe a filter */
#define COEF_PER_FILTER (5 * NUMBER_OF_STAGES)

#define NUMBER_OF_BANDS (8)

#define MAX_GAIN (10)

#define GAIN_LEVELS (MAX_GAIN*2 + 1)

/*Filter gain on init*/
#define DEFAULT_GAIN (0)

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Initialize equalizer.
 * 
 */
void EQ_Init(void);

/**
 * @brief Sets  equalizer filter gains.
 * @param gain  number in dB with the desired gain of the filter
 * @param band selected band in which to change gain (between 1 and NUMBER_OF_BANDS)
 */
void EQ_Set_Band_Gain (int32_t band, int32_t gain);

/**
 * @brief returns equalizer filter gains.
 * @return gain  number in dB 
 * @param band selected band in which to change gain (between 1 and NUMBER_OF_BANDS)
 */
int32_t EQ_Get_Band_Gain (int32_t band);

/**
 * @brief Applies the filter to the data in inputF32 and stores the result in outputF32
 * @param inputF32  pointer to an array of size FRAME_SIZE with input data
 * @param outputF32 pointer to an array of size FRAME_SIZE //!(will be overwritten)
 */
void EQ_Apply(float32_t* inputF32, float32_t * outputF32);

#endif
