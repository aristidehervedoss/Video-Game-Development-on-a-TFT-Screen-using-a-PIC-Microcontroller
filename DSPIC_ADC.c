

#include "TIME_FCT.h"

void init_ADC_manual (void)
{   
    AD1CON1 = 0x0400;
    //AD1CON1 = 0x0000;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x0009;
    AD1CON4 = 0x0000;
    AD1CHS123 = 0x0000;
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    
    AD1CHS0 = 0x0000;
    
    _ADON = 1;
    
    wait_ms (1);
}

int ADC_get (void)
{
AD1CON1bits.SAMP = 1;           // Start sampling
wait_us(1);                     // Wait for sampling time (1 us)
AD1CON1bits.SAMP = 0;           // Start the conversion
while (!AD1CON1bits.DONE);      // Wait for the conversion to complete
return ADC1BUF0;                // Read the ADC conversion result
}

void init_ADC_manual_ch (char ADC_channel)
{
    AD1CON1 = 0x0400;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x0009;
    AD1CON4 = 0x0000;
    AD1CHS123 = 0x0000;
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    
    AD1CHS0 = ADC_channel;
 
    _ADON = 1;
    
    wait_ms (1);
}


