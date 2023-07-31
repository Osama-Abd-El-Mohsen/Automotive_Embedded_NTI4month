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
#include "KPD_private.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "DIO_interface.h"
char sevseg[] = {0b0111111, 0x06, 0x5b, 0b1001111, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

u8 KPD_u8iniit()
{
    /*define rows as input and colms as outputs*/
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW0, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW1, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW2, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_ROW3, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL0, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL1, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL2, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(KPD_PORT, KPD_COL3, DIO_PIN_OUTPUT);

    /*intial values for rows to enable internal pullup*/
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW0, DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW1, DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW2, DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_ROW3, DIO_PIN_HIGH);
    DIO_u8SetPinValue(KPD_PORT, KPD_COL0, DIO_PIN_LOW);
    DIO_u8SetPinValue(KPD_PORT, KPD_COL1, DIO_PIN_LOW);
    DIO_u8SetPinValue(KPD_PORT, KPD_COL2, DIO_PIN_LOW);
    DIO_u8SetPinValue(KPD_PORT, KPD_COL3, DIO_PIN_LOW);
}

u8 KPD_u8ReturnPressed()
{
    DIO_u8SetPortValue(KPD_PORT,INIT_COL_VALUE);
    for (u8 i = 0; i < KPD_COLS; i++)
    {
        for (u8 j = 0; j < KPD_ROWS; j++)
        {
            if (GET_BIT(KPD_PORT,KPD_ROW0) == 0)
            {
                sevseg[i];
            }
            else if (GET_BIT(KPD_PORT,KPD_ROW1) == 0)
            {
                sevseg[i];
            }

            else if (GET_BIT(KPD_PORT,KPD_ROW2) == 0)
            {
                sevseg[i];
            }
            
        }

        
    }

    
}