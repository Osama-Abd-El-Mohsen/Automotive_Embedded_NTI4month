/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    LIB				       ***********/
/***********    SWC    :    DIO_PROGRAM 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "SSD_private.h"
#include "DIO/DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
u8 SSDARR[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};

u8 SSD_u8Display(SSD_t *Copy_SSD, u8 Copy_u8Value)
{
    /*declaring error state varaible*/
    u8 Local_u8StateError = OK;

    /*set SSD port direction*/
    DIO_u8SetPortDirection(Copy_SSD->SSD_u8Port, DIO_PORT_OUTPUT);

    /*setting port value in binary to display*/
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_ANODE:
        DIO_u8SetPortValue(Copy_SSD->SSD_u8Port,SSDARR[Copy_u8Value]);
        break;
    case SSD_COM_CATHODE:
        DIO_u8SetPortValue(Copy_SSD->SSD_u8Port,~SSDARR[Copy_u8Value]);
        break;
    
    default:
    Local_u8StateError=NOK;
        break;
    }

    return Local_u8StateError;
}

u8 SSD_u8Enable(SSD_t *Copy_SSD)
{
    u8 Local_u8StateError = OK;
    /*set SSD enable pin direction*/
    DIO_u8SetPinDirection(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, DIO_PIN_OUTPUT);
    /*check common connection type*/
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_CATHODE:
        /*set com pin value*/
        DIO_u8SetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, DIO_PIN_LOW);
        break;

    case SSD_COM_ANODE:
        /*set com pin value*/
        DIO_u8SetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, DIO_PIN_HIGH);

        break;

    default:
        Local_u8StateError = NOK;
        break;
    }
    return Local_u8StateError;
}

u8 SSD_u8Disable(SSD_t *Copy_SSD)
{
    u8 Local_u8StateError = OK;
    /*check common connection type*/
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_CATHODE:
        /*set com pin value*/
        DIO_u8SetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, DIO_PIN_HIGH);
        break;

    case SSD_COM_ANODE:
        /*set com pin value*/
        DIO_u8SetPinValue(Copy_SSD->SSD_u8EnablePort, Copy_SSD->SSD_u8EnablePin, DIO_PIN_LOW);

        break;

    default:
        Local_u8StateError = NOK;
        break;
    }
    return Local_u8StateError;
}

u8 SSD_u8Clear(SSD_t *Copy_SSD)
{
    /*declaring error state variable*/
    u8 Local_u8StateError = OK;
    switch (Copy_SSD->SSD_u8CommonType)
    {
    case SSD_COM_CATHODE:
        DIO_u8SetPortValue(Copy_SSD->SSD_u8Port, PORT_LOW);
        break;

    case SSD_COM_ANODE:
        DIO_u8SetPortValue(Copy_SSD->SSD_u8Port, PORT_HIGH);
        break;

    default:
        Local_u8StateError = NOK;
        break;
    }
    return Local_u8StateError;
}