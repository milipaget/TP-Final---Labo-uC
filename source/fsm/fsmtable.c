#include <stdio.h>
#include "fsm.h"
#include "fsmtable.h"


/*declaración de estados*/

extern STATE idle[];
extern STATE volume[];
extern STATE equalizer[];
extern STATE repoducing[];
extern STATE error[]; //noSD originalmente

// prototipos

static void do_nothing(void);
static void reset_FSM(void);
static void match (void);

#define EQTYPE 4
const char *eqTypes[EQTYPE] = {"Flat", "Rock", "Pop", "Bass"};

/*** tablas de estado ***/

STATE idle[]=
{
  	//{'D',estado_1,do_nothing},
  	//{'R',estado_1,do_nothing},
  	{FIN_TABLA,idle,do_nothing}
};

 STATE volume[]=
{
  	//{'D',estado_1,do_nothing},
  	//{'R',estado_1,do_nothing},
  	{FIN_TABLA,idle,do_nothing}
};

STATE equalizer[]=
{
  	//{'D',estado_1,do_nothing},
  	//{'R',estado_1,do_nothing},
  	{FIN_TABLA,idle,do_nothing}
};

 STATE reproducing[]=
{
  	//{'D',estado_1,do_nothing},
  	//{'R',estado_1,do_nothing},
  	{FIN_TABLA,idle,do_nothing}
};

STATE error[]=
{
  	//{'D',estado_1,do_nothing},
  	//{'R',estado_1,do_nothing},
  	{FIN_TABLA,idle,do_nothing}
};

//========interfaz=================


STATE *FSM_GetInitState(void)
{
 	return (idle);
}

///=========Rutinas de accion===============

/*Dummy function*/
static void do_nothing(void)
{

}

