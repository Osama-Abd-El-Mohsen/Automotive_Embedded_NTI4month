/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    LIB				       ***********/
/***********    SWC    :    DIO_PROGRAM 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_interface.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir)
{
    u8 Local_u8State = 0;
    if (Copy_u8Pin <= DIO_PIN7)
    {
        if (Copy_u8Dir == DIO_PIN_OUTPUT)
        {
            switch (Copy_u8Port)
            {
            case DIO_PORTA:
                SET_BIT(DDRA, Copy_u8Pin);
                break;
            case DIO_PORTB:
                SET_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_PORTC:
                SET_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_PORTD:
                SET_BIT(DDRD, Copy_u8Pin);
                break;
            default:
                Local_u8State = 1;
                break;
            }
        }
        else if (Copy_u8Dir == DIO_PIN_INPUT)
        {
            switch (Copy_u8Port)
            {
            case DIO_PORTA:
                CLR_BIT(DDRA, Copy_u8Pin);
                break;
            case DIO_PORTB:
                CLR_BIT(DDRB, Copy_u8Pin);
                break;
            case DIO_PORTC:
                CLR_BIT(DDRC, Copy_u8Pin);
                break;
            case DIO_PORTD:
                CLR_BIT(DDRD, Copy_u8Pin);
                break;
            default:
                Local_u8State = 1;
                break;
            }
        }
        else
            Local_u8State = 1;
    }
    else
        Local_u8State = 1;

    return Local_u8State;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Dir)
{
    u8 Local_u8State = 0;

    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        DDRA = Copy_u8Dir;
        break;
    case DIO_PORTB:
        DDRB = Copy_u8Dir;
        break;
    case DIO_PORTC:
        DDRC = Copy_u8Dir;
        break;
    case DIO_PORTD:
        DDRD = Copy_u8Dir;
        break;
    default:
        Local_u8State = 1;
        break;
    }

    return Local_u8State;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Val)
{
    u8 Local_u8State = 0;
    if (Copy_u8Pin <= DIO_PIN7)
    {
        if (Copy_u8Val == DIO_PIN_HIGH)
        {
            switch (Copy_u8Port)
            {
            case DIO_PORTA:
                SET_BIT(PORTA, Copy_u8Pin);
                break;
            case DIO_PORTB:
                SET_BIT(PORTB, Copy_u8Pin);
                break;
            case DIO_PORTC:
                SET_BIT(PORTC, Copy_u8Pin);
                break;
            case DIO_PORTD:
                SET_BIT(PORTD, Copy_u8Pin);
                break;
            default:
                Local_u8State = 1;
                break;
            }
        }
        else if (Copy_u8Val == DIO_PIN_LOW)
        {
            switch (Copy_u8Port)
            {
            case DIO_PORTA:
                CLR_BIT(PORTA, Copy_u8Pin);
                break;
            case DIO_PORTB:
                CLR_BIT(PORTB, Copy_u8Pin);
                break;
            case DIO_PORTC:
                CLR_BIT(PORTC, Copy_u8Pin);
                break;
            case DIO_PORTD:
                CLR_BIT(PORTD, Copy_u8Pin);
                break;
            default:
                Local_u8State = 1;
                break;
            }
        }
        else
            Local_u8State = 1;
    }
    else
        Local_u8State = 1;
    return Local_u8State;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Val)
{
    u8 Local_u8State = 0;

    switch (Copy_u8Port)
    {
    case DIO_PORTA:
        PORTA = Copy_u8Val;
        break;
    case DIO_PORTB:
        PORTB = Copy_u8Val;
        break;
    case DIO_PORTC:
        PORTC = Copy_u8Val;
        break;
    case DIO_PORTD:
        PORTD = Copy_u8Val;
        break;
    default:
        Local_u8State = 1;
        break;
    }

    return Local_u8State;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
    u8 Local_u8State = 0;
    if (Copy_pu8Value != NULL_POINTER && Copy_u8Pin <= DIO_PIN7)
    {
        switch (Copy_u8Port)
        {
        case DIO_PORTA:
            *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);
            break;
        case DIO_PORTB:
            *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin);
            break;
        case DIO_PORTC:
            *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin);
            break;
        case DIO_PORTD:
            *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin);
            break;
        default:
            Local_u8State = 1;
            break;
        }
    }
    else
        Local_u8State = 1;

    return Local_u8State;
}