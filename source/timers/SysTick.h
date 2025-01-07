/***************************************************************************//**
  @file     SysTick.h
  @brief    SysTick driver
  @author   Nicolás Magliola
 ******************************************************************************/
#ifndef _SYSTICK_H_
#define _SYSTICK_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include "MK64F12.h"
#include "../../SDK/startup/hardware.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define SYSTICK_ISR_FREQUENCY_HZ 1000U  //estaba en 1000

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Initialize SysTic driver
 * @param funcallback Function to be call every SysTick
 * @return Initialization and registration succeed
 */
bool SysTick_Init (void (*funcallback)(void));

/*******************************************************************************
 ******************************************************************************/

#endif // _SYSTICK_H_
