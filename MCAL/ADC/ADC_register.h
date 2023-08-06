/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL				   ***********/
/***********    SWC    :    ADC_REGISTER_H 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX *((volatile u8 *)0X27)
#define ADMUX_REDS1_BIT 7
#define ADMUX_REDS0_BIT 6
#define ADMUX_ADLAR_BIT 5
#define ADMUX_MUX4_BIT 4
#define ADMUX_MUX3_BIT 3
#define ADMUX_MUX2_BIT 2
#define ADMUX_MUX1_BIT 1
#define ADMUX_MUX0_BIT 0

#define ADCSRA *((volatile u8 *)0X26)
#define ADCSRA_ADEN_BIT 7
#define ADCSRA_ADSC_BIT 6
#define ADCSRA_ADATE_BIT 5
#define ADCSRA_ADIF_BIT 4
#define ADCSRA_ADIE_BIT 3
#define ADCSRA_ADPS2_BIT 2
#define ADCSRA_ADPS1_BIT 1
#define ADCSRA_ADPS0_BIT 0

#define ADCH *((volatile u8 *)0X25)
#define ADCL *((volatile u8 *)0X24)
#define ADC *((volatile u16*)0x24)


#endif