/*******************************************************************************
   @file    pinout.h
   @brief   Archivo que contiene las constantes de los pines utilizados
   @author  Grupo 4 Laboratorio de Microprocesadores:
  	  	  	Corcos, Manuel
  	  	  	Lesiuk, Alejandro
  	  	  	Paget, Milagros
  	  	  	Voss, Maria de Guadalupe
  ******************************************************************************/

#ifndef _PINOUT_H_
#define _PINOUT_H_

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
//Pines utilizados para el encoder
#define PORT_ENCODER_RCHA
#define PORT_ENCODER_RCHB
#define PORT_ENCODER_BUTTON

//Pines utilizados para los botones
#define ON_OFF_BUTTON_PIN 8
#define NEXT_BUTTON_PIN 9
#define PREV_BUTTON_PIN 10
#define CHANGE_FILTER_BUTTON_PIN 11

// Pines para encoder
	#define ENCODER_OUT_A PORTNUM2PIN(PB, 2)
	#define ENCODER_OUT_B PORTNUM2PIN(PB, 3)
  #define BUTTON_ENCODER_PIN PORTNUM2PIN(PC, 5) // Botón del encoder

//Pines utilizados para la matriz de LEDs

/*******************************************************************************
 ******************************************************************************/

#endif // _PINOUT_H_