/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL 				   ***********/
/***********    SWC    :    LCD_INTERFACE 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*=============INIT=============*/
/*clear LCD*/
#define LCD_CLR_SCREEN 0b00000001
/*Return cursor to first place*/
#define LCD_RETURN_HOME 0b00000010
/*turn LCD on or off*/
#define LCD_TURN_ON 0b000001100
#define LCD_TURN_OFF 0b000001000

/*=============ENTRY_MODE=============*/
/*ENTRY_MODE Modes*/
#define LCD_ENTRY_MODE_INC_SH_RIGHT 1
#define LCD_ENTRY_MODE_DNC_SH_LEFT 2
#define LCD_ENTRY_MODE_INC_NO_SH 3
#define LCD_ENTRY_MODE_DNC_NO_SH 4

/*=============DISPLAY_ON_OFF=============*/
/*DISPLAY_ON_OFF Modes*/
#define LCD_CURSOR_MODE_ON 1
#define LCD_CURSOR_MODE_OFF 2
#define LCD_CURSOR_BLINK_MODE_ON 3
#define LCD_CURSOR_BLINK_MODE_OFF 4

/*=============CURSOR OR DISPLAY SHIFT (CODS)=============*/
/*CURSOR OR DISPLAY SHIFT Modes*/
#define LCD_DISPLAY_SHIFT_CURSOR_LEFT 1
#define LCD_DISPLAY_SHIFT_CURSOR_RIGHT 2
#define LCD_DISPLAY_SHIFT_ALL_LEFT 3
#define LCD_DISPLAY_SHIFT_ALL_RIGHT 4

/*=============FUNCTION_SET=============*/
/*FUNCTION_SET Modes*/
#define LCD_FUNCTION_SET_8BIT 8
#define LCD_FUNCTION_SET_4BIT 4
#define LCD_FUNCTION_SET_1LINE_CONTROL 1
#define LCD_FUNCTION_SET_2LINE_CONTROL 2
#define LCD_FUNCTION_SET_DISPLAY_LINE_5_8 5
#define LCD_FUNCTION_SET_DISPLAY_LINE_5_11 11

/*LCD_INIT*/
void LCD_voidINIT(void);

/*LCD_CLR*/
void LCD_voidClear(void);

/*LCD_ReturnHome*/
void LCD_voidReturnHome(void);

/*LCD change cursor position*/
u8 LCD_u8GoToRow_Col(u8 Copy_u8Row, u8 Copy_u8Col);

/*LCD send integer number*/
u8 LCD_u8SendInt(u8 Copy_u8Row, u8 Copy_u8Col, u8 Copy_u8Int);

/*LCD send spechial character*/
void LCD_voidWriteSpechialChar(u8 *Copy_u8Pattern, u8 Copy_u8Patternnumber, u8 Copy_u8Row, u8 Copy_u8Col);



/*LCD_Turnon and off*/
void LCD_voidTurnOn(void);
void LCD_voidTurnOff(void);

/*LCD_SEND_COMMAND*/
void LCD_voidSendCommand(u8 Copy_u8Command);

/*LCD_SEND_COMMAND*/
void LCD_voidSendData(u8 Copy_u8Data);
u8 LCD_u8SendString(u8 *Copy_pu8String);
/* ENTRY_MODE Set Mode
Options :
LCD_ENTRY_MODE_INC_SH_RIGHT
LCD_ENTRY_MODE_DNC_SH_LEFT
LCD_ENTRY_MODE_INC_NO_SH
LCD_ENTRY_MODE_DNC_NO_SH
*/
u8 LCD_u8EntryMode(u8 Copy_u8Mode);

/* CURSOR Mode
Options :
LCD_CURSOR_MODE_ON
LCD_CURSOR_MODE_OFF
*/
u8 LCD_u8CursorMode(u8 Copy_u8Mode);

/*Cursor Blink Modes
Options :
LCD_CURSOR_BLINK_MODE_ON
LCD_CURSOR_BLINK_MODE_OFF
*/
u8 LCD_u8CursorBlinkMode(u8 Copy_u8Mode);

/* DISPLAY SHIFT (CODS)  Modes
Options :
LCD_DISPLAY_SHIFT_CURSOR_LEFT
LCD_DISPLAY_SHIFT_CURSOR_RIGHT
LCD_DISPLAY_SHIFT_ALL_LEFT
LCD_DISPLAY_SHIFT_ALL_RIGHT
*/
u8 LCD_u8DisplayShift(u8 Copy_u8Mode);

#endif