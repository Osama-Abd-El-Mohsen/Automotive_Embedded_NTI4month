/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL				   ***********/
/***********    SWC    :    ADC_CONFIG_H 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*set refrence selection bit 
===========================
            OPTIONS 
===========================
1- ADC_REF_BIT_AREF
2- ADC_REF_BIT_AVCC
3- ADC_REF_BIT_INTRNAL_2_56V
*/
#define ADC_REF_SELECTION_BIT ADC_REF_BIT_AVCC

/*Left Or Right Adjust Result
===========================
            OPTIONS 
===========================
1- ADC_LEFT_ADJUST
2- ADC_RIGHT_ADJUST
*/
#define ADC_ADLAR_RESULT ADC_LEFT_ADJUST

/*Auto Trigger Enable 
===========================
            OPTIONS 
===========================
1- ADC_AUTO_TRIGGER_ENABLE
2- ADC_AUTO_TRIGGER_DISABLE
*/

#define ADC_AUTO_TRIGGER_STATE ADC_AUTO_TRIGGER_DISABLE

/* ADC Prescaler Select Bits
===========================
            OPTIONS 
===========================
1- ADC_DIV_BY_2
2- ADC_DIV_BY_4
3- ADC_DIV_BY_8
4- ADC_DIV_BY_16
5- ADC_DIV_BY_32
6- ADC_DIV_BY_64
7- ADC_DIV_BY_128
*/
#define ADC_PRESCALER_SELECT ADC_DIV_BY_64

#endif