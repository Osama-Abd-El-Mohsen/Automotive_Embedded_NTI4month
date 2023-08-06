/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL 				   ***********/
/***********    SWC    :    LED_PROGRAM       	   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/STD_TYPES.h"
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"
#include "DIO/DIO_interface.h"

u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Pin <= DIO_PIN7)
    {
        DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin, DIO_PIN_OUTPUT);
        switch (Copy_u8Type)
        {
        case LED_U8SOURCE:
            DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_HIGH);
            break;

        case LED_U8SINK:
            DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_LOW);
            break;

        default:
            Local_u8ErrorState = NOK;
            break;
        }
    }
    else
        Local_u8ErrorState = NOK;

    return Local_u8ErrorState;
}

u8 LED_u8TurnOff(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_u8Pin <= DIO_PIN7)
    {
        DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin, DIO_PIN_OUTPUT);
        switch (Copy_u8Type)
        {
        case LED_U8SOURCE:
            DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_LOW);
            break;

        case LED_U8SINK:
            DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, DIO_PIN_HIGH);
            break;

        default:
            Local_u8ErrorState = NOK;
            break;
        }
    }
    else
        Local_u8ErrorState = NOK;

    return Local_u8ErrorState;
}

u8 LED_u8PortTurnOn(u8 Copy_u8Port, u8 Copy_u8Type)
{
    u8 Local_u8ErrorState = OK;

    DIO_u8SetPortDirection(Copy_u8Port, DIO_PORT_OUTPUT);
    switch (Copy_u8Type)
    {
    case LED_U8SOURCE:
        DIO_u8SetPortValue(Copy_u8Port, DIO_PORT_HIGH);
        break;

    case LED_U8SINK:
        DIO_u8SetPortValue(Copy_u8Port, DIO_PORT_LOW);
        break;

    default:
        Local_u8ErrorState = NOK;
        break;
    }

    return Local_u8ErrorState;
}

u8 LED_u8PortTurnOff(u8 Copy_u8Port, u8 Copy_u8Type)
{
    u8 Local_u8ErrorState = OK;

    DIO_u8SetPortDirection(Copy_u8Port, DIO_PORT_OUTPUT);
    switch (Copy_u8Type)
    {
    case LED_U8SOURCE:
        DIO_u8SetPortValue(Copy_u8Port, DIO_PORT_LOW);
        break;

    case LED_U8SINK:
        DIO_u8SetPortValue(Copy_u8Port, DIO_PORT_HIGH);
        break;

    default:
        Local_u8ErrorState = NOK;
        break;
    }

    return Local_u8ErrorState;
}