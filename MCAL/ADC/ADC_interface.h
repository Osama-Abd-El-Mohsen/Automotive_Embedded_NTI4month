/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL				   ***********/
/***********    SWC    :    ADC_INTERFACE_H 	   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

/*************************************************************/
/**    Description :    Initialization ADC                  **/
/**    Return      :    void				                **/
/**    Parameters  :    void				                **/
/*************************************************************/
void ADC_voidInit(void);

/*************************************************************/
/**    Description :    Getting chhannel reading            **/
/**    Return      :    Errorstate reading in memory	    **/
/**    Parameters  :    ADC channel variable address        **/
/*************************************************************/
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel, u16 *Copy_pu16Reading);

#endif