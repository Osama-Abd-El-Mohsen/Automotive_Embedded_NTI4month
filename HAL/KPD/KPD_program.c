/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL				       ***********/
/***********    SWC    :    KPD_PROGRAM 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "DIO/DIO_interface.h"

void KPD_u8iniit()
{
    /*define rows as input and colms as outputs*/
    DIO_u8SetPortDirection(KPD_PORT, 0X0F);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL0, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL1, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL2, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL3, DIO_PIN_OUTPUT);

    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW0, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW1, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW2, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW3, DIO_PIN_INPUT);

    /*intial values for rows to enable internal pullup*/
    DIO_u8SetPortValue(KPD_PORT, 0XFF);
}

void KPD_u8ReturnPressed(u8 *Copy_pu8Value)
{
    *Copy_pu8Value = KPD_NO_PRESSED_KEY;
    u8 Local_u8PinValue = TWO;
    u8 Local_u8ColCounter = ZERO;
    u8 Local_u8RowCounter = ZERO;
    static u8 Local_u8KPDRowArr[KPD_ROWS] = {KPD_ROW0, KPD_ROW1, KPD_ROW2, KPD_ROW3};
    static u8 Local_u8KPDColArr[KPD_COLS] = {KPD_COL0, KPD_COL1, KPD_COL2, KPD_COL3};

    for (Local_u8ColCounter = ZERO; Local_u8ColCounter < KPD_COLS; Local_u8ColCounter++)
    {
        /*setting next colume to low (Active next colume)*/
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColArr[Local_u8ColCounter], DIO_PIN_LOW);

        /*check which button will be low (Active)*/
        for (Local_u8RowCounter = ZERO; Local_u8RowCounter < KPD_ROWS; Local_u8RowCounter++)
        {
            DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowCounter], &Local_u8PinValue);
            if (!Local_u8PinValue)
            {
                /*fix deboucing problem*/
                while (!Local_u8PinValue)
                {
                    DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowCounter], &Local_u8PinValue);
                }

                /*returning pressed value*/
                *Copy_pu8Value = KPD_u8arr[Local_u8RowCounter][Local_u8ColCounter];
            }
        }
        /*set colume pin to high (deactive)*/
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColArr[Local_u8ColCounter], DIO_PIN_HIGH);
    }
}
