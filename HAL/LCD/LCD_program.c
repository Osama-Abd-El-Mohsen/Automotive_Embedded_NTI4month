/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL				       ***********/
/***********    SWC    :    LCD_PROGRAM 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "util/delay.h"

u8 LCD_ENTRY_MODE_VALUE = 0b00000100;
u8 LCD_DISPLAY_ON_OFF_VALUE = 0b00001000;
u8 LCD_CODS_VALUE = 0b00010011;
u8 LCD_FUNCTION_SET_VALUE = 0b00100011;

void LCD_voidClear(void)
{
    LCD_voidSendCommand(LCD_CLR_SCREEN);
}

void LCD_voidReturnHome(void)
{
    LCD_voidSendCommand(LCD_RETURN_HOME);
}

void LCD_voidTurnOn(void)
{
    LCD_voidSendCommand(LCD_TURN_ON);
}

void LCD_voidTurnOff(void)
{
    LCD_voidSendCommand(LCD_TURN_OFF);
}

void LCD_voidINIT(void)
{
    /*clearing and reutern cursor to home */
    LCD_voidSendCommand(LCD_CLR_SCREEN);
    LCD_voidSendCommand(LCD_RETURN_HOME);
    LCD_voidSendCommand(LCD_TURN_ON);

    /* setting data port and controll pins directions */
    DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
    DIO_u8SetPinDirection(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(LCD_CONTROLL_PORT, LCD_RW_BIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_OUTPUT);

    /* config LCD INIT modes */
#if LCD_BIT_MODE == LCD_FUNCTION_SET_8BIT
    SET_BIT(LCD_FUNCTION_SET_VALUE, LCD_FUNCTION_SET_DL_BIT);
#elif LCD_BIT_MODE == LCD_FUNCTION_SET_4BIT
    CLR_BIT(LCD_FUNCTION_SET_VALUE, LCD_FUNCTION_SET_DL_BIT);
#endif

#if LCD_LINE_MODE == LCD_FUNCTION_SET_2LINE_CONTROL
    SET_BIT(LCD_FUNCTION_SET_VALUE, LCD_FUNCTION_SET_N_BIT);
#elif LCD_LINE_MODE == LCD_FUNCTION_SET_1LINE_CONTROL
    CLR_BIT(LCD_FUNCTION_SET_VALUE, LCD_FUNCTION_SET_N_BIT);
#endif

#if LCD_DISPLAY_LINE_MODE == LCD_FUNCTION_SET_DISPLAY_LINE_5_8
    CLR_BIT(LCD_FUNCTION_SET_VALUE, LCD_FUNCTION_SET_F_BIT);
#elif LCD_DISPLAY_LINE_MODE == LCD_FUNCTION_SET_DISPLAY_LINE_5_11
    SET_BIT(LCD_FUNCTION_SET_VALUE, LCD_FUNCTION_SET_F_BIT);
#endif
    /*setting RS , RW pins initial values to zero*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_LOW);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RW_BIN, DIO_PIN_LOW);

    LCD_voidSendCommand(LCD_FUNCTION_SET_VALUE);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    /*sending command*/
    DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

    /*set RS pin to low to send command*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_LOW);

    /*Generating Enable Puls to send the Command */
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    /*sending data*/
    DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

    /*set RS pin to high to send data*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_HIGH);

    /*Generating Enable Puls to send the data */
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_LOW);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_LOW);
}
u8 LCD_u8SendString(u8 *Copy_pu8String)
{
    /*declaring error state variable */
    u8 Local_u8ErrorState = OK;
    u8 Local_u8Counter= ZERO;
    while (*(Copy_pu8String+Local_u8Counter) != '\0')
    {
        LCD_voidSendData(*(Copy_pu8String+Local_u8Counter));
        Local_u8Counter++;
    }
    

    return Local_u8ErrorState;
}

u8 LCD_u8EntryMode(u8 Copy_u8Mode)
{
    /*declaring error state variable */
    u8 Local_u8ErrorState = OK;
    /*config modes*/
    switch (Copy_u8Mode)
    {
    case LCD_ENTRY_MODE_INC_SH_RIGHT:
        SET_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_ID_BIT);
        SET_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_SH_BIT);
        break;
    case LCD_ENTRY_MODE_DNC_SH_LEFT:
        CLR_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_ID_BIT);
        SET_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_SH_BIT);
        break;
    case LCD_ENTRY_MODE_INC_NO_SH:
        SET_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_ID_BIT);
        CLR_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_SH_BIT);
        break;
    case LCD_ENTRY_MODE_DNC_NO_SH:
        SET_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_ID_BIT);
        CLR_BIT(LCD_ENTRY_MODE_VALUE, LCD_ENTRY_MODE_SH_BIT);
        break;

    default:
        Local_u8ErrorState = NOK;
        break;
    }
    /*apply modes*/
    LCD_voidSendCommand(LCD_ENTRY_MODE_VALUE);
    return Local_u8ErrorState;
}

/* CURSOR Mode
Options :
LCD_CURSOR_MODE_ON
LCD_CURSOR_MODE_OFF
*/
u8 LCD_u8CursorMode(u8 Copy_u8Mode)
{
    /*declaring error state variable */
    u8 Local_u8ErrorState = OK;
    /*config modes*/
    switch (Copy_u8Mode)
    {
    case LCD_CURSOR_MODE_ON:
        SET_BIT(LCD_DISPLAY_ON_OFF_VALUE, LCD_DISPLAY_ON_OFF_D_BIT);
        SET_BIT(LCD_DISPLAY_ON_OFF_VALUE, LCD_DISPLAY_ON_OFF_C_BIT);
        break;

    case LCD_CURSOR_MODE_OFF:
        SET_BIT(LCD_DISPLAY_ON_OFF_VALUE, LCD_DISPLAY_ON_OFF_D_BIT);
        CLR_BIT(LCD_DISPLAY_ON_OFF_VALUE, LCD_DISPLAY_ON_OFF_C_BIT);
        break;

    default:
        Local_u8ErrorState = NOK;
        break;
    }
    /*apply modes*/
    LCD_voidSendCommand(LCD_DISPLAY_ON_OFF_VALUE);
    return Local_u8ErrorState;
}

/*Cursor Blink Modes
Options :
LCD_CURSOR_BLINK_MODE_ON
LCD_CURSOR_BLINK_MODE_OFF
*/
u8 LCD_u8CursorBlinkMode(u8 Copy_u8Mode)
{
    /*declaring error state variable */
    u8 Local_u8ErrorState = OK;

    /*config modes*/
    switch (Copy_u8Mode)
    {
    case LCD_CURSOR_BLINK_MODE_ON:
        SET_BIT(LCD_DISPLAY_ON_OFF_VALUE, LCD_DISPLAY_ON_OFF_B_BIT);
        break;

    case LCD_CURSOR_BLINK_MODE_OFF:
        CLR_BIT(LCD_DISPLAY_ON_OFF_VALUE, LCD_DISPLAY_ON_OFF_B_BIT);
        break;

    default:
        Local_u8ErrorState = NOK;
        break;
    }

    /*Apply modes*/
    LCD_voidSendCommand(LCD_DISPLAY_ON_OFF_VALUE);
    return Local_u8ErrorState;
}

/* DISPLAY SHIFT (CODS)  Modes
Options :
LCD_DISPLAY_SHIFT_CURSOR_LEFT
LCD_DISPLAY_SHIFT_CURSOR_RIGHT
LCD_DISPLAY_SHIFT_ALL_LEFT
LCD_DISPLAY_SHIFT_ALL_RIGHT
*/
u8 LCD_u8DisplayShift(u8 Copy_u8Mode)
{
    /*declaring error state variable */
    u8 Local_u8ErrorState = OK;

    /*config modes*/
    switch (Copy_u8Mode)
    {
    case LCD_DISPLAY_SHIFT_CURSOR_LEFT:
        CLR_BIT(LCD_CODS_VALUE, LCD_CODS_SC_BIT);
        CLR_BIT(LCD_CODS_VALUE, LCD_CODS_RL_BIT);
        break;
    case LCD_DISPLAY_SHIFT_CURSOR_RIGHT:
        CLR_BIT(LCD_CODS_VALUE, LCD_CODS_SC_BIT);
        SET_BIT(LCD_CODS_VALUE, LCD_CODS_RL_BIT);
        break;
    case LCD_DISPLAY_SHIFT_ALL_LEFT:
        SET_BIT(LCD_CODS_VALUE, LCD_CODS_SC_BIT);
        CLR_BIT(LCD_CODS_VALUE, LCD_CODS_RL_BIT);
        break;
    case LCD_DISPLAY_SHIFT_ALL_RIGHT:
        SET_BIT(LCD_CODS_VALUE, LCD_CODS_SC_BIT);
        SET_BIT(LCD_CODS_VALUE, LCD_CODS_RL_BIT);
        break;

    default:
        break;
    }

    /*apply modes*/
    LCD_voidSendCommand(LCD_CODS_VALUE);
    return Local_u8ErrorState;
}