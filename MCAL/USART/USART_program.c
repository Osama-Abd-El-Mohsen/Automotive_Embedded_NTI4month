/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    USART_PROGRAM          ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "USART/USART_config.h"
#include "USART/USART_register.h"
#include "USART/USART_private.h"
#include "USART/USART_interface.h"

u32 Power(u8 Copy_u8base, u8 Copy_u8exponent);

void USART_voidInit(void)
{
    u8 Local_u8UCSRCValue = ZERO;
    u8 Local_u8BoudRate = ZERO;

    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_URSEL);
    /*setting USART type */
#if USART_TYPE == USART_SYNCHRONOUS
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UMSEL);
    Local_u8BoudRate = (USART_FOSC / ((u32)USART_BAUD)2 *)-ONE;

#elif USART_TYPE == USART_ASYNCHRONOUS
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UMSEL);
    /*config u2x speed (asynchronous only)*/
#if USART_DOUBLE_TR_SPEED == USART_U2X_ENABLE
    SET_BIT(USART_UCSRA, USART_UCSRA_U2X);
    Local_u8BoudRate = (USART_FOSC / ((u32)USART_BAUD)8 *)-ONE;
#elif USART_DOUBLE_TR_SPEED == USART_U2X_DISABLE
    CLR_BIT(USART_UCSRA, USART_UCSRA_U2X);
    Local_u8BoudRate = (USART_FOSC / ((u32)USART_BAUD * 16)) - ONE;
#endif
#endif

/*Config multi processor mode*/
#if USART_MULTI_PROC_MODE == USART_MULTI_PROC_ENABLE
    SET_BIT(USART_UCSRA, USART_UCSRA_MPCM);
#elif USART_MULTI_PROC_MODE == USART_MULTI_PROC_DISABLE
    CLR_BIT(USART_UCSRA, USART_UCSRA_MPCM);
#endif

/*setting character size mode*/
#if USART_CHAR_SIZE_SEL == USART_CHAR_SIZE_5BIT
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, USART_UCSRB_UCSZ2);
#elif USART_CHAR_SIZE_SEL == USART_CHAR_SIZE_6BIT
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ0);
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, USART_UCSRB_UCSZ2);
#elif USART_CHAR_SIZE_SEL == USART_CHAR_SIZE_7BIT
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, USART_UCSRB_UCSZ2);
#elif USART_CHAR_SIZE_SEL == USART_CHAR_SIZE_8BIT
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ1);
    CLR_BIT(USART_UCSRB, USART_UCSRB_UCSZ2);
#elif USART_CHAR_SIZE_SEL == USART_CHAR_SIZE_9BIT
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ0);
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UCSZ1);
    SET_BIT(USART_UCSRB, USART_UCSRB_UCSZ2);
#endif

/*setting parity mode*/
#if USART_PARITY_MODE == USART_PARITY_DISABLE
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UPM1);
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UPM0);
#elif USART_PARITY_MODE == USART_PARITY_EVEN
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UPM1);
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_UPM0);
#elif USART_PARITY_MODE == USART_PARITY_ODD
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UPM1);
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_UPM0);
#endif

#if USART_STOP_MODE == USART_STOP_1BIT
    CLR_BIT(Local_u8UCSRCValue, USART_UCSRC_USBS);
#elif USART_STOP_MODE == USART_STOP_2BIT
    SET_BIT(Local_u8UCSRCValue, USART_UCSRC_USBS);
#endif

    /*setting UCSRC register value*/
    USART_UCSRC = Local_u8UCSRCValue;

    /*setting interrupts enable*/
    /* RX Complete Interrupt Enable*/
    SET_BIT(USART_UCSRB, USART_UCSRB_RXCIE);
    /* TX Complete Interrupt Enable*/
    SET_BIT(USART_UCSRB, USART_UCSRB_TXCIE);
    /*  USART Data Register Empty Interrupt Enable*/
    SET_BIT(USART_UCSRB, USART_UCSRB_UDRIE);

    /*setting boud rate*/
    USART_UBRRL = Local_u8BoudRate;
    SET_BIT(USART_UCSRB, USART_UCSRB_RXEN);
    SET_BIT(USART_UCSRB, USART_UCSRB_TXEN);
}

u8 USART_u8Receive(void)
{
    /*wait until usart receving data*/
    while (GET_BIT(USART_UCSRA, USART_UCSRA_RXC) == ZERO)
        ;
    return USART_UDR;
}

void USART_voidSend(u8 Copy_u8Data)
{
    /*wait until Data Register be Empty*/
    USART_UDR = Copy_u8Data;
    while (GET_BIT(USART_UCSRA, USART_UCSRA_UDRE) == ZERO)
        ;
}

void USART_voidSendString(u8 *Copy_u8Data)
{
    u8 Local_u8Counter = ZERO;
    while ((Copy_u8Data[Local_u8Counter]) != '\0')
    {
        USART_voidSend(Copy_u8Data[Local_u8Counter]);
        Local_u8Counter++;
    }
}

void USART_voidSendInt(u32 Copy_u32Int)
{
    u8 Local_u8RemindNum = ONE;
    u8 Local_u8Counter = ZERO;
    u32 Copy_u32Int2 = Copy_u32Int;

    /*Getting int lenght*/
    while (Copy_u32Int2 != ZERO)
    {
        Local_u8RemindNum = Copy_u32Int % TEN_VAL;
        Copy_u32Int2 = Copy_u32Int2 / TEN_VAL;
        Local_u8Counter++;
    }

    Local_u8Counter--;
    u8 Local_u8TempCounter =Local_u8Counter;
    u8 IntArr[Local_u8Counter];

    /*printing int*/
    while (Copy_u32Int != ZERO)
    {
        Local_u8RemindNum = Copy_u32Int % TEN_VAL;
        Copy_u32Int = Copy_u32Int / TEN_VAL;
        IntArr[Local_u8Counter] = Local_u8RemindNum;
        Local_u8Counter--;
    }

    for (u8 LoopCounter = 0; LoopCounter <= Local_u8TempCounter; LoopCounter++)
    {
    USART_voidSend(ZERO_ASCII_CODE + IntArr[LoopCounter]);
    }
    
}

/*Display float number on USART*/
void USART_voidSendFloat(f32 Copy_u32Float, u8 Copy_u8DigitNumber)
{
    u8 Local_u8RemindNum = ONE;
    u8 Local_u8Counter = ZERO;
    u32 Copy_u32Int2 = Copy_u32Float;

    /*Getting float lenght*/
    while (Copy_u32Int2 != ZERO)
    {
        Local_u8RemindNum = (u32)Copy_u32Float % TEN_VAL;
        Copy_u32Int2 = Copy_u32Int2 / TEN_VAL;
        Local_u8Counter++;
    }

    /*sending int part */
    USART_voidSendInt((u32)Copy_u32Float);

    /*go to postion after int part and sennding '.' */
    USART_voidSend('.');

    /*converting float part into int part and display it*/
    USART_voidSendInt((u32)((Copy_u32Float - (u32)Copy_u32Float) * Power(10, Copy_u8DigitNumber)));
}

u32 Power(u8 Copy_u8base, u8 Copy_u8exponent)
{
    u32 Local_u8Result = ONE;
    for (u8 Local_u8Counter = ONE; Local_u8Counter <= Copy_u8exponent; Local_u8Counter++)
    {
        Local_u8Result *= Copy_u8base;
    }
    return Local_u8Result;
}
