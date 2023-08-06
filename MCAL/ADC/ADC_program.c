/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    ADC_PROGRAM_H          ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "ADC/ADC_register.h"
#include "ADC/ADC_private.h"
#include "ADC/ADC_config.h"
#include "ADC/ADC_interface.h"
#include "DIO/DIO_interface.h"

void ADC_voidInit(void)
{

    /*set ADEN pin to high (to enable adc)*/
    SET_BIT(ADCSRA, ADCSRA_ADEN_BIT);

    /*setting refrence voltage bit*/
#if ADC_REF_SELECTION_BIT == ADC_REF_BIT_AVCC
    {
        SET_BIT(ADMUX, ADMUX_REDS0_BIT);
        CLR_BIT(ADMUX, ADMUX_REDS1_BIT);
    }
#elif ADC_REF_SELECTION_BIT == ADC_REF_BIT_AREF
    {
        CLR_BIT(ADMUX, ADMUX_REDS0_BIT);
        CLR_BIT(ADMUX, ADMUX_REDS1_BIT);
    }

#elif ADC_REF_SELECTION_BIT == ADC_REF_BIT_INTRNAL_2_56V
    {
        SET_BIT(ADMUX, ADMUX_REDS0_BIT);
        SET_BIT(ADMUX, ADMUX_REDS1_BIT);
    }
#endif

/*selecting right and left adjust*/
#if ADC_ADLAR_RESULT == ADC_LEFT_ADJUST
    {
        SET_BIT(ADMUX, ADMUX_ADLAR_BIT);
    }
#elif ADC_ADLAR_RESULT == ADC_RIGHT_ADJUST
    {
        CLR_BIT(ADMUX, ADMUX_ADLAR_BIT);
    }
#endif

/*Enable And Disable Auto Trigger*/
#if ADC_AUTO_TRIGGER_STATE == ADC_AUTO_TRIGGER_ENABLE
    {
        SET_BIT(ADCSRA, ADCSRA_ADATE_BIT);
    }
#elif ADC_AUTO_TRIGGER_STATE == ADC_AUTO_TRIGGER_DISABLE
    {
        CLR_BIT(ADCSRA, ADCSRA_ADATE_BIT);
    }
#endif

/*Select Prescaler*/
#if ADC_PRESCALER_SELECT == ADC_DIV_BY_2
    {
        CLR_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        CLR_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#elif ADC_PRESCALER_SELECT == ADC_DIV_BY_4
    {
        CLR_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        CLR_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#elif ADC_PRESCALER_SELECT == ADC_DIV_BY_8
    {
        CLR_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#elif ADC_PRESCALER_SELECT == ADC_DIV_BY_16
    {
        SET_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        CLR_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        CLR_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#elif ADC_PRESCALER_SELECT == ADC_DIV_BY_32
    {
        SET_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        CLR_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#elif ADC_PRESCALER_SELECT == ADC_DIV_BY_64
    {
        SET_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        CLR_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#elif ADC_PRESCALER_SELECT == ADC_DIV_BY_128
    {
        SET_BIT(ADCSRA, ADCSRA_ADPS2_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS1_BIT);
        SET_BIT(ADCSRA, ADCSRA_ADPS0_BIT);
    }
#endif
}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel, u16 *Copy_pu16Reading)
{
    ADMUX &= ADC_MUX_MUSK;
    ADMUX |= Copy_u8Channel;
    SET_BIT(ADCSRA, ADCSRA_ADSC_BIT);
    while (GET_BIT(ADCSRA, ADCSRA_ADIF_BIT) == ZERO)
        ;
    SET_BIT(ADCSRA, ADCSRA_ADIF_BIT);
#if ADC_ADLAR_RESULT == ADC_LEFT_ADJUST
    {
        ADCL=ADCL>>6;
        ADCH=ADCH<<2;
        *Copy_pu16Reading = ADCL+ADCH;
    }

#elif ADC_ADLAR_RESULT == ADC_RIGHT_ADJUST
    {
        *Copy_pu16Reading = ADC;
    }
#endif
}