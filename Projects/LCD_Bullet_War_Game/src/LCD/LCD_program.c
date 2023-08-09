/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL                    ***********/
/***********    SWC    :    LCD_PROGRAM            ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO/DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "util/delay.h"

u32 Power(u8 Copy_u8base, u8 Copy_u8exponent);

u8 LCD_ENTRY_MODE_VALUE = 0b00000100;
u8 LCD_DISPLAY_ON_OFF_VALUE = 0b00001000;
u8 LCD_CODS_VALUE = 0b00010011;
u8 LCD_FUNCTION_SET_VALUE = 0b00100011;

/*Clearing LCD*/
void LCD_voidClear(void)
{
    LCD_voidSendCommand(LCD_CLR_SCREEN);
}

/*Return Cursor to home (first col & first raw)*/
void LCD_voidReturnHome(void)
{
    LCD_voidSendCommand(LCD_RETURN_HOME);
}

/*turnning on LCD*/
void LCD_voidTurnOn(void)
{
    LCD_voidSendCommand(LCD_TURN_ON);
}

/*turnning off LCD*/
void LCD_voidTurnOff(void)
{
    LCD_voidSendCommand(LCD_TURN_OFF);
}

/*init lcd*/
void LCD_voidINIT(void)
{
    /* setting data port and controll pins directions */
    DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
    DIO_u8SetPinDirection(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(LCD_CONTROLL_PORT, LCD_RW_BIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_OUTPUT);

    /*datasheet init delay more than 30 ms*/
    _delay_ms(40);

    /*clearing and reutern cursor to home */
    LCD_voidSendCommand(LCD_TURN_ON);

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

    LCD_voidSendCommand(LCD_CLR_SCREEN);
    LCD_voidSendCommand(LCD_RETURN_HOME);

    /*setting RS , RW pins initial values to zero*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_LOW);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RW_BIN, DIO_PIN_LOW);

    LCD_voidSendCommand(LCD_FUNCTION_SET_VALUE);
}

/*sending command to lcd*/
void LCD_voidSendCommand(u8 Copy_u8Command)
{
    /*sending command*/
    DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Command);

    /*set RS pin to low to send command*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_LOW);

    /*set RW pin to low for write*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RW_BIN, DIO_PIN_LOW);

    /*Generating Enable Puls to send the Command and reading data */
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_LOW);
}

/*sending data to lcd*/
void LCD_voidSendData(u8 Copy_u8Data)
{

    /*set RS pin to high to send data*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_HIGH);

    /*set RW pin to low for write*/
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RW_BIN, DIO_PIN_LOW);

    /*sending data*/
    DIO_u8SetPortValue(LCD_DATA_PORT, Copy_u8Data);

    /*Generating Enable Puls to send the data */
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_HIGH);
    _delay_ms(2);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_ENABLE_BIN, DIO_PIN_LOW);
    DIO_u8SetPinValue(LCD_CONTROLL_PORT, LCD_RS_BIN, DIO_PIN_LOW);
}

/*sending string to lcd*/
u8 LCD_u8SendString(u8 Copy_u8Row, u8 Copy_u8Col, u8 *Copy_pu8String)
{
    /*declaring error state variable */
    u8 Local_u8ErrorState = OK;
    u8 Local_u8Counter = ZERO;

    while (*(Copy_pu8String + Local_u8Counter) != '\0')
    {
        LCD_voidGoToRow_Col(Copy_u8Row, Copy_u8Col);
        LCD_voidSendData(*(Copy_pu8String + Local_u8Counter));
        Local_u8Counter++, Copy_u8Col++;
        if (Copy_u8Col == LCD_LAST_COL_INDEX)
        {
            Copy_u8Col = ZERO;
            Copy_u8Row++;
            if (Copy_u8Row == LCD_LAST_RAW_INDEX)
            {
                Copy_u8Row = ZERO;
            }
            else
                Local_u8ErrorState = NOK;
        }
        else
            Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

/*sending integer number to lcd*/
void LCD_voidSendInt(u8 Copy_u8Row, u8 Copy_u8Col, u32 Copy_u32Int)
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

    /*printing int*/
    while (Copy_u32Int != ZERO)
    {
        LCD_voidGoToRow_Col(Copy_u8Row, Copy_u8Col + Local_u8Counter);

        Local_u8RemindNum = Copy_u32Int % TEN_VAL;
        Copy_u32Int = Copy_u32Int / TEN_VAL;
        LCD_voidSendData(ZERO_ASCII_CODE + Local_u8RemindNum);
        Local_u8Counter--;
    }
}

/*Display float number on lcd*/
void LCD_voidSendFloat(u8 Copy_u8Row, u8 Copy_u8Col, f32 Copy_u32Float, u8 Copy_u8DigitNumber)
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
    LCD_voidSendInt(Copy_u8Row, Copy_u8Col, (u32)Copy_u32Float);

    /*go to postion after int part and sennding '.' */
    LCD_voidGoToRow_Col(Copy_u8Row, Copy_u8Col + Local_u8Counter);
    LCD_voidSendData('.');

    /*converting float part into int part and display it*/
    LCD_voidSendInt(Copy_u8Row, Copy_u8Col + Local_u8Counter + ONE, (u32)((Copy_u32Float - (u32)Copy_u32Float) * Power(10, Copy_u8DigitNumber)));
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

/*creating and sending spechial char to lcd*/
void LCD_voidWriteSpechialChar(u8 *Copy_u8Pattern, u8 Copy_u8Patternnumber, u8 Copy_u8Row, u8 Copy_u8Col)
{
    if (Copy_u8Patternnumber <= CGRAM_SC_SIZE)
    {
        u8 Local_u8Counter;

        /*setting CGRAM Start Addresse */
        u8 Local_u8CGRAMAddress = Copy_u8Patternnumber * CGRAM_SC_SIZE;

        /*setting CGRAM Addresse */
        LCD_voidSendCommand(Local_u8CGRAMAddress + CGRAM_ADD);

        /*Entering Spechial Char Data */
        for (Local_u8Counter = ZERO; Local_u8Counter < CGRAM_SC_SIZE; Local_u8Counter++)
        {
            LCD_voidSendData(Copy_u8Pattern[Local_u8Counter]);
        }

        /*Display Spechial Char  */
        LCD_voidGoToRow_Col(Copy_u8Row, Copy_u8Col);
        LCD_voidSendData(Copy_u8Patternnumber);
    }
}

/* ENTRY_MODE Set Mode
Options :
LCD_ENTRY_MODE_INC_SH_RIGHT
LCD_ENTRY_MODE_DNC_SH_LEFT
LCD_ENTRY_MODE_INC_NO_SH
LCD_ENTRY_MODE_DNC_NO_SH
*/
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
        Local_u8ErrorState = NOK;
        break;
    }

    /*apply modes*/
    LCD_voidSendCommand(LCD_CODS_VALUE);
    return Local_u8ErrorState;
}

void LCD_voidGoToRow_Col(u8 Copy_u8Row, u8 Copy_u8Col)
{
    if (Copy_u8Row == ZERO)
    {
        /*first line*/
        LCD_voidSendCommand(DDRAM_FIRST_COL_ADD + Copy_u8Col);
    }
    else
        /*2nd line*/
        LCD_voidSendCommand(DDRAM_2ND_COL_ADD + Copy_u8Col);
}
