/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    LIB                    ***********/
/***********    SWC    :    SW_PROGRAM             ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO/DIO_interface.h"
#include "SW_config.h"
#include "SW_private.h"
#include "SW_interface.h"

u8 SW_u8StatePressed(SW_T *SW_struckt, u8 *Copy_pu8Value)
{

    u8 Local_u8ErrorState = OK;
    if (SW_struckt->Copy_u8Pin <= DIO_PIN7)
    {
        /*set pin direction to input*/
        DIO_u8SetPinDirection(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, DIO_PIN_INPUT);
        /*get pin value*/
        if (SW_struckt->Copy_u8ConnType == SW_U8INTERNAL_PULL_UP)
        {
            DIO_u8SetPinValue(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, DIO_PIN_HIGH);
            DIO_u8GetPinValue(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, Copy_pu8Value);
        }
        else
            DIO_u8GetPinValue(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, Copy_pu8Value);
        /*check connection type*/
        if (SW_struckt->Copy_u8LockState == SW_U8NOT_SELF_LOCKING)
        {
            switch (SW_struckt->Copy_u8ConnType)
            {
            case SW_U8PULL_UP:
            
                if (!*Copy_pu8Value)
                {
                    while (!*Copy_pu8Value)
                        DIO_u8GetPinValue(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, Copy_pu8Value);
                    /*set variable value to pressed if pressed*/
                    *Copy_pu8Value = SW_PRESSED;
                }
                else{
                    *Copy_pu8Value = SW_NOT_PRESSED;}

                break;

            case SW_U8PULL_DOWN:
                if (*Copy_pu8Value)
                {
                    while (*Copy_pu8Value)
                        DIO_u8GetPinValue(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, Copy_pu8Value);
                    *Copy_pu8Value = SW_PRESSED;
                }
                else
                    *Copy_pu8Value = SW_NOT_PRESSED;

                break;
            case SW_U8INTERNAL_PULL_UP:
                if (!*Copy_pu8Value)
                {
                    while (!*Copy_pu8Value)
                        DIO_u8GetPinValue(SW_struckt->Copy_u8Port, SW_struckt->Copy_u8Pin, Copy_pu8Value);
                    *Copy_pu8Value = SW_PRESSED;
                }
                else
                    *Copy_pu8Value = SW_NOT_PRESSED;

                break;

            default:
                Local_u8ErrorState = NOK;
                break;
            }
        }
        else
        {
            switch (SW_struckt->Copy_u8ConnType)
            {
            case SW_U8PULL_UP:
                if (!*Copy_pu8Value)
                {
                    /*set variable value to pressed if pressed*/
                    *Copy_pu8Value = SW_PRESSED;
                }
                else
                    *Copy_pu8Value = SW_NOT_PRESSED;

                break;

            case SW_U8PULL_DOWN:
                if (*Copy_pu8Value)
                {
                    *Copy_pu8Value = SW_PRESSED;
                }
                else
                    *Copy_pu8Value = SW_NOT_PRESSED;

                break;
            case SW_U8INTERNAL_PULL_UP:
                if (!*Copy_pu8Value)
                {
                    *Copy_pu8Value = SW_PRESSED;
                }
                else
                    *Copy_pu8Value = SW_NOT_PRESSED;

                break;

            default:
                Local_u8ErrorState = NOK;
                break;
            }
        }
    }
    else
        Local_u8ErrorState = NOK;

    return Local_u8ErrorState;
}