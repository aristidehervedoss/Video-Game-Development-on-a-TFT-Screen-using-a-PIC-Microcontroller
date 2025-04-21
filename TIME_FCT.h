/* 
 * File:                DSPIC_TFT.H
 * Author:              Julien CLaudel
 * Comments:
 * Revision history:    26 juillet 2017
 */


#ifndef DEF_TIME_FCT
#define DEF_TIME_FCT

#include <xc.h> // include processor files - each processor file is guarded.  

//fonction permettant d'intialiser le PLL pour obtenir une vitesse processeur de 50 MIPS
void Fosc_init (void);

//fonction permettant de compter environ N ms
void wait_ms (unsigned int);

//fonction permettant de compter environ N µs
void wait_us (unsigned int);

//fonction permettant d'initialiser le timer 32 bit
void init_tmr3 (long);

//fonction permettant d'initialiser le timer 32 bit en mode interruption
void init_tmr3_interrupt (long);

#endif