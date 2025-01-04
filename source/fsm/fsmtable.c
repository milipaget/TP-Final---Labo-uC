#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "fsm.h"
#include "fsmtable.h"
#include "../mp3Config.h"
#include "../eventos/eventQueue.h"

/*declaración de estados*/

extern STATE idle[]; //El equipo está prendido y se hacen los updates de las variables
extern STATE off[]; //Está "apagado", bajo consumo (no hace nada básicamente)
extern STATE errorState[]; //noSD originalmente

// prototipos

static void do_nothing(void);
static void increaseVolumeCount(void);
static void decreaseVolumeCount(void);
static void changePlayingState(void);
static void decreaseSongPointer(void);
static void increaseSongPointer(void);
static void changeToOff(void);
static void changeToOn(void);
static void increaseFilterCount(void);
static void changeToSDError(void);
static void changeToSongError(void);
static void changeToNoError(void);
static void checkSD(void);

/*** tablas de estado ***/
//{EVENTO, PRÓXIMO ESTADO, ACCIÓN A REALIZAR}

//TENEMOS QUE AGREGAR UNA INTERRUPCIÓN QUE SEA UPDATEAR LAS COSAS!!

STATE idle[]=
{
  	{None, idle, do_nothing},
  	{volumeUP, idle, increaseVolumeCount}, //Incremento la variable que tenga el nivel del volumen
	{volumeDOWN, idle, decreaseVolumeCount}, //Decremento la variable que tenga el nivel del volumen
	{playPause, idle, changePlayingState}, //Niego el estado anterior de reproducción
	{prevSong, idle, decreaseSongPointer}, //Decremento el puntero a la canción anterior
	{nextSong, idle, increaseSongPointer}, //Incremento el puntero a la canción anterior
	{onOff, off, changeToOff}, //Pongo modo off
	{changeFilter, idle, increaseFilterCount}, //Paso al siguiente filtro
	{SDCardOut, errorState, changeToSDError}, //Pongo en modo error
  	{FIN_TABLA, idle, do_nothing}
};

 STATE off[]=
{
  	{onOff, idle, changeToOn}, //Pongo modo on
	//Capaz hay que agregar lo de la SD
  	{FIN_TABLA,idle,do_nothing}
};

STATE errorState[]=
{
	//Capaz hay que agregar lo de off
  	{SDCardIn, idle, checkSD}, //Pongo en modo error
  	{FIN_TABLA, idle ,do_nothing}
};

//========interfaz=================


STATE *FSM_GetInitState(void)
{
	/*if(songNum == 0){
		changeToSongError();
		return (error);
	}*/
 	return (idle);
}

///=========Rutinas de accion===============

/*Dummy function*/
static void do_nothing(void){

}

static void increaseVolumeCount(void){
	if(mp3ConfigVariables.volume < MAX_VOLUME){
		mp3ConfigVariables.volume++;
	}
}

static void decreaseVolumeCount(void){
	if(mp3ConfigVariables.volume > 0){
		mp3ConfigVariables.volume--;
	}
}

static void changePlayingState(void){
	mp3ConfigVariables.volume = !mp3ConfigVariables.volume;
}

static void decreaseSongPointer(void){
	if(mp3ConfigVariables.songPointer > 0){
		mp3ConfigVariables.songPointer--; 
	}
	else if(mp3ConfigVariables.songPointer == 0){
		mp3ConfigVariables.songPointer = songNum;
	}
}

static void increaseSongPointer(void){
	if(mp3ConfigVariables.songPointer < songNum){
		mp3ConfigVariables.songPointer++; 
	}
	else if(mp3ConfigVariables.songPointer == songNum){
		mp3ConfigVariables.songPointer = 0;
	}
}

static void changeToOff(void){
	mp3ConfigVariables.isOn = false;
}

static void changeToOn(void){
	mp3ConfigVariables.isOn = true;
}

static void increaseFilterCount(void){
	if(mp3ConfigVariables.filterType < EQTYPE){
		mp3ConfigVariables.filterType++; 
	}
	else if(mp3ConfigVariables.filterType == EQTYPE){
		mp3ConfigVariables.filterType = 0;
	}
}

static void changeToSDError(void){
	mp3ConfigVariables.errorType = NO_SD;
}

static void changeToSongError(void){
	mp3ConfigVariables.errorType = NO_SONGS;
}

static void changeToNoError(void){
	mp3ConfigVariables.errorType = NONE;
}

static void checkSD(void){
	//initSD();
	/*if(songNum == 0){
		changeToSongError();
	}
	else{
		changeToNoError();
	}*/
	changeToNoError();
}
