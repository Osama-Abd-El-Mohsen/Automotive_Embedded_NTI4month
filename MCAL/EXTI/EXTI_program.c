/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    EXTI_PROGRAM           ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "EXTI/EXTI_register.h"
#include "EXTI/EXTI_private.h"
#include "EXTI/EXTI_config.h"
#include "EXTI/EXTI_interface.h"
#include "DIO/DIO_interface.h"

void (*EXTI_INT0_ISR_FUNC)(void) = NULL;
void (*EXTI_INT1_ISR_FUNC)(void) = NULL;
void (*EXTI_INT2_ISR_FUNC)(void) = NULL;

u8 EXTI_u8INT0_Mode(u8 Copy_u8INT0Mode)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8INT0Mode < 4 && Copy_u8INT0Mode > 0)
    {
        EXTI_MCUCR = Copy_u8INT0Mode;
    }
    else
        Local_u8ErrorState = NOK;
    return Local_u8ErrorState;
}

u8 EXTI_u8INT1_Mode(u8 Copy_u8INT1Mode)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8INT1Mode < 4 && Copy_u8INT1Mode > 0)
    {
        EXTI_MCUCR = Copy_u8INT1Mode << 2;
    }
    else
        Local_u8ErrorState = NOK;
    return Local_u8ErrorState;
}

u8 EXTI_u8INT2_Mode(u8 Copy_u8INT1Mode)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8INT1Mode == EXTI_INT2_FALLING_EDGE)
    {
        CLR_BIT(EXTI_MCUCSR, EXTI_MCUCR_ISC2);
    }
    else if (Copy_u8INT1Mode == EXTI_INT2_RISING_EDGE)
    {
        SET_BIT(EXTI_MCUCSR, EXTI_MCUCR_ISC2);
    }
    else
        Local_u8ErrorState = NOK;
    return Local_u8ErrorState;
}

void EXTI_voidINT0_Enable(void)
{
    SET_BIT(EXTI_GICR, EXTI_GICR_INT0);
}

void EXTI_voidINT1_Enable(void)
{
    SET_BIT(EXTI_GICR, EXTI_GICR_INT1);
}

void EXTI_voidINT2_Enable(void)
{
    SET_BIT(EXTI_GICR, EXTI_GICR_INT2);
}

void EXTI_voidINT0_Disable(void)
{
    CLR_BIT(EXTI_GICR, EXTI_GICR_INT0);
}

void EXTI_voidINT1_Disable(void)
{
    CLR_BIT(EXTI_GICR, EXTI_GICR_INT1);
}

void EXTI_voidINT2_Disable(void)
{
    CLR_BIT(EXTI_GICR, EXTI_GICR_INT2);
}

void EXTI_voidINT0_SetCallbackFunc(void (*Copy_pvInt0Func)(void))
{
    if (Copy_pvInt0Func != NULL)
    {
        EXTI_INT0_ISR_FUNC = Copy_pvInt0Func;
    }
}

void EXTI_voidINT1_SetCallbackFunc(void (*Copy_pvInt1Func)(void))
{
    if (Copy_pvInt1Func != NULL)
    {
        EXTI_INT1_ISR_FUNC = Copy_pvInt1Func;
    }
}

void EXTI_voidINT2_SetCallbackFunc(void (*Copy_pvInt2Func)(void))
{
    if (Copy_pvInt2Func != NULL)
    {
        EXTI_INT2_ISR_FUNC = Copy_pvInt2Func;
    }
}

void __vector_1(void) __attribute__((signal, used));
void __vector_1(void)
{
    if (EXTI_INT0_ISR_FUNC != NULL)
    {
        EXTI_INT0_ISR_FUNC();
    }
}

void __vector_2(void) __attribute__((signal, used));
void __vector_2(void)
{
    if (EXTI_INT1_ISR_FUNC != NULL)
    {
        EXTI_INT1_ISR_FUNC();
    }
}

void __vector_3(void) __attribute__((signal, used));
void __vector_3(void)
{
    if (EXTI_INT2_ISR_FUNC != NULL)
    {
        EXTI_INT2_ISR_FUNC();
    }
}