/*
 * File:   TIME_FCT.c
 * Author: jclaudel
 *
 * Created on 26 juillet 2017, 10:37
 */


#include "xc.h"
#include "TIME_FCT.h"

void Fosc_init ()
{
    // Fosc = Fin * M / (N1*N2); M = PLLDIV+2; N1 = PLLPRE + 2; N2 = 2*(PLLLPOST + 1) //
    
    _PLLDIV = 48;       // (0x00 to 0xFF -> 2 to 513)           M=50(default)
    _PLLPRE = 0;        // (0x00 to 0xFF -> N1= 2 to 33)        N1=2(default)
    _PLLPOST = 0;       // (0x00, 0x01 or 0x11 -> N2=2,4 or 8)  N2=2(default)
}

void wait_ms (unsigned int wait_time)
{
    unsigned int wait_T1,wait_T2;
    wait_T1=0;
    wait_T2=0;
    
    while (wait_T2 < wait_time)
    {
    while (wait_T1<8750)
    {
        wait_T1++;
    }
    wait_T1=0;
    wait_T2++;
    }
}

void wait_us (unsigned int wait_time)
{
    unsigned int wait_T1,wait_T2;
    wait_T1=0;
    wait_T2=0;
    
    while (wait_T2 < wait_time)
    {
    while (wait_T1<8)
    {
        wait_T1++;
    }
    wait_T1=0;
    wait_T2++;
    }
}

void init_tmr3 (long TMR_cpt)
{
    int TMR_cptM, TMR_cptL;
    TMR_cptM = (TMR_cpt>>16) & 0x0000FFFF;
    TMR_cptL = (TMR_cpt) & 0x0000FFFF;
    T3CONbits.TON = 0;        // Stop any 16-bit Timer3 operation
    T2CONbits.TON = 0;        // Stop any 16/32-bit Timer3 operation
    IEC0bits.T3IE = 0;        // Disable Timer3 interrupt
    T2CONbits.T32 = 1;        // Enable 32-bit Timer mode
    T2CONbits.TCS = 0;        // Select internal instruction cycle clock 
    T2CONbits.TGATE = 0;      // Disable Gated Timer mode
    T2CONbits.TCKPS = 0b00;   // Select 1:1 Prescaler
    TMR3 = 0x00;              // Clear 32-bit Timer (msw)
    TMR2 = 0x00;              // Clear 32-bit Timer (lsw)
    PR3 = TMR_cptM;           // Load 32-bit period value (msw)
    PR2 = TMR_cptL;           // Load 32-bit period value (lsw)
    IPC2bits.T3IP = 0x01;     // Set Timer3 Interrupt Priority Level
    IFS0bits.T3IF = 0;        // Clear Timer3 Interrupt Flag
    T2CONbits.TON = 1;        // Start 32-bit Timer
}

void init_tmr3_interrupt (long TMR_cpt)
{
    int TMR_cptM, TMR_cptL;
    TMR_cptM = (TMR_cpt>>16) & 0x0000FFFF;
    TMR_cptL = (TMR_cpt) & 0x0000FFFF;
    T3CONbits.TON = 0;        // Stop any 16-bit Timer3 operation
    T2CONbits.TON = 0;        // Stop any 16/32-bit Timer3 operation
    T2CONbits.T32 = 1;        // Enable 32-bit Timer mode
    T2CONbits.TCS = 0;        // Select internal instruction cycle clock 
    T2CONbits.TGATE = 0;      // Disable Gated Timer mode
    T2CONbits.TCKPS = 0b00;   // Select 1:1 Prescaler
    TMR3 = 0x00;              // Clear 32-bit Timer (msw)
    TMR2 = 0x00;              // Clear 32-bit Timer (lsw)
    PR3 = TMR_cptM;           // Load 32-bit period value (msw)
    PR2 = TMR_cptL;           // Load 32-bit period value (lsw)
    IPC2bits.T3IP = 0x01;     // Set Timer3 Interrupt Priority Level
    IFS0bits.T3IF = 0;        // Clear Timer3 Interrupt Flag
    IEC0bits.T3IE = 1;        // Enable Timer3 interrupt
    T2CONbits.TON = 1;        // Start 32-bit Timer
}