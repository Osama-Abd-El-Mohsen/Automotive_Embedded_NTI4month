/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL                    ***********/
/***********    SWC    :    LCD_INTERFACE          ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

/*Preprossesor file guard*/
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

/*************************************************************/
/**    Description :    Initialization LCD 8 or 4 Bit       **/
/**    Return      :    void                                **/
/**    Parameters  :    void                                **/
/*************************************************************/
void LCD_voidINIT(void);

/*************************************************************/
/**    Description :    Clear LCD                           **/
/**    Return      :    void                                **/
/**    Parameters  :    void                                **/
/*************************************************************/
void LCD_voidClear(void);

/*LCD_ReturnHome*/
/*************************************************************/
/**    Description :    Ruturn cursor to home 0,0 position  **/
/**    Return      :    void                                **/
/**    Parameters  :    void                                **/
/*************************************************************/
void LCD_voidReturnHome(void);

/*************************************************************/
/**    Description :    Changing LCD cursor position        **/
/**    Return      :    void                                **/
/**    Parameters  :    Row & Colume position               **/
/*************************************************************/
void LCD_voidGoToRow_Col(u8 Copy_u8Row, u8 Copy_u8Col);

/*************************************************************/
/**    Description :    Display integer number on LCD       **/
/**    Return      :    void                                **/
/**    Parameters  :    Row,Colume position and int number  **/
/*************************************************************/
void LCD_voidSendInt(u8 Copy_u8Row, u8 Copy_u8Col, u32 Copy_u32Int);

/*************************************************************/
/**    Description :    Display float number on LCD         **/
/**    Return      :    void                                **/
/**    Parameters  :    Row,Col position and float number   **/
/*************************************************************/
void LCD_voidSendFloat(u8 Copy_u8Row, u8 Copy_u8Col, f32 Copy_u32Float,u8 Copy_u8DigitNumber);

/*************************************************************/
/**    Description :    Display spechial character on LCD   **/
/**    Return      :    void                                **/
/**    Parameters  :    character patternArray,patternNumber**/
/**    & row,col position                                   **/
/*************************************************************/
void LCD_voidWriteSpechialChar(u8 *Copy_u8Pattern, u8 Copy_u8Patternnumber, u8 Copy_u8Row, u8 Copy_u8Col);

/*************************************************************/
/**    Description :    Send data on LCD                    **/
/**    Return      :    void                                **/
/**    Parameters  :    data                                **/
/*************************************************************/
void LCD_voidSendData(u8 Copy_u8Data);

/*************************************************************/
/**    Description :    Send command on LCD                 **/
/**    Return      :    void                                **/
/**    Parameters  :    command                             **/
/*************************************************************/
void LCD_voidSendCommand(u8 Copy_u8Command);

/*************************************************************/
/**    Description :    Display string on LCD               **/
/**    Return      :    void                                **/
/**    Parameters  :    row,colume position and the string  **/
/*************************************************************/
u8 LCD_u8SendString(u8 Copy_u8Row, u8 Copy_u8Col, u8 *Copy_pu8String);

/*************************************************************/
/**    Description :    turnning on or off LCD              **/
/**    Return      :    void                                **/
/**    Parameters  :    void                                **/
/*************************************************************/
void LCD_voidTurnOn(void);
void LCD_voidTurnOff(void);

/*************************************************************/
/**    Description :    Changing entry mode                 **/
/**    Return      :    Errorstate                          **/
/**    Parameters  :    mode                                **/
/**    Options     :                                        **/
/**                 1-LCD_ENTRY_MODE_INC_SH_RIGHT           **/
/**                 2-LCD_ENTRY_MODE_DNC_SH_LEFT            **/
/**                 3-LCD_ENTRY_MODE_INC_NO_SH              **/
/**                 4-LCD_ENTRY_MODE_DNC_NO_SH              **/
/*************************************************************/
u8 LCD_u8EntryMode(u8 Copy_u8Mode);

/*************************************************************/
/**    Description :    Changing cursor mode                **/
/**    Return      :    Errorstate                          **/
/**    Parameters  :    mode                                **/
/**    Options     :                                        **/
/**                 1-LCD_CURSOR_MODE_ON                    **/
/**                 2-LCD_CURSOR_MODE_OFF                   **/
/*************************************************************/
u8 LCD_u8CursorMode(u8 Copy_u8Mode);

/*************************************************************/
/**    Description :    Changing cursor Blink Mode          **/
/**    Return      :    Errorstate                          **/
/**    Parameters  :    mode                                **/
/**    Options     :                                        **/
/**                 1-LCD_CURSOR_BLINK_MODE_ON              **/
/**                 2-LCD_CURSOR_BLINK_MODE_OFF             **/
/*************************************************************/
u8 LCD_u8CursorBlinkMode(u8 Copy_u8Mode);

/*************************************************************/
/**    Description :    Changing DISPLAY SHIFT (CODS)  Mode **/
/**    Return      :    Errorstate                          **/
/**    Parameters  :    mode                                **/
/**    Options     :                                        **/
/**                 1-LCD_DISPLAY_SHIFT_CURSOR_LEFT         **/
/**                 2-LCD_DISPLAY_SHIFT_CURSOR_RIGHT        **/
/**                 2-LCD_DISPLAY_SHIFT_ALL_LEFT            **/
/**                 2-LCD_DISPLAY_SHIFT_ALL_RIGHT           **/
/*************************************************************/
u8 LCD_u8DisplayShift(u8 Copy_u8Mode);

#endif