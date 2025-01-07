/*******************************************************************************
   @file    eventQueue.h
   @brief   Event handler
   @author  Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
  ******************************************************************************/

#ifndef _EVENTQUEUE_H_
#define _EVENTQUEUE_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef enum event_type
{
  None,
  volumeUP,
  volumeDOWN,
  playPause,
  prevSong,
  nextSong,
  onOff,
  changeFilter, 
  //AutoNextSong,
  SDCardOut,
  SDCardIn
} event_t;

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief FSM Principal del proyecto
 * @param parametro utilizado dentro de la FSM para guardar los datos que se van escribiendo
 */

event_t getNextEvent(void);
void putEvent(event_t event);
event_t popEvent(void);
/*******************************************************************************
 ******************************************************************************/

#endif // _EVENTQUEUE_H_
