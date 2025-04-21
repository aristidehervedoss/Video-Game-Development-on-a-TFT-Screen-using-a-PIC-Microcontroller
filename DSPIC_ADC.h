/* 
 * File:   DSPIC_ADC.h
 * Author: claudel16
 *
 * Created on 23 octobre 2018, 09:36
 */

#ifndef DSPIC_ADC_H
#define	DSPIC_ADC_H

void init_ADC_manual (void);
void init_ADC_manual_ch (char ADC_channel);

int ADC_get (void);

#endif	/* DSPIC_ADC_H */

