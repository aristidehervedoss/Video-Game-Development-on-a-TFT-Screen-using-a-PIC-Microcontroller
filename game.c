#include "xc.h"
#include "TIME_FCT.h"
#include "DSPIC_TFT.h"


void init_joystick (void)
{
    _ANSA6 = 0;
    _ANSA7 = 0;
    _TRISA1 = 1;
    
    _TRISA4 = 1;
    _TRISA5 = 1;
    _TRISA6 = 1;
    _TRISA7 = 1;
}