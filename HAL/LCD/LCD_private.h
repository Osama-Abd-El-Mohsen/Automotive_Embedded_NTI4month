/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL                    ***********/
/***********    SWC    :    LCD_PRIVATE            ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

/*Preprossesor file guard*/
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/*=============MAGIC NUMS============= */
#define DDRAM_FIRST_COL_ADD 0x80
#define DDRAM_2ND_COL_ADD 0xc0
#define ZERO_ASCII_CODE '0'
#define TEN_VAL 10
#define CGRAM_SC_SIZE 8
#define CGRAM_ADD 64
#define LCD_LAST_COL_INDEX 16
#define LCD_LAST_RAW_INDEX 2

/*=============INIT=============*/
/*clear LCD*/
#define LCD_CLR_SCREEN 0b00000001
/*Return cursor to first place*/
#define LCD_RETURN_HOME 0b00000010
/*turn LCD on or off*/
#define LCD_TURN_ON 0b000001100
#define LCD_TURN_OFF 0b000001000

/*=============ENTRY_MODE=============*/
/*ENTRY_MODE BIT NUMBERS*/
#define LCD_ENTRY_MODE_ID_BIT 1
#define LCD_ENTRY_MODE_SH_BIT 0

/*ENTRY_MODE Modes*/
#define LCD_ENTRY_MODE_INC_SH_RIGHT 1
#define LCD_ENTRY_MODE_DNC_SH_LEFT 2
#define LCD_ENTRY_MODE_INC_NO_SH 3
#define LCD_ENTRY_MODE_DNC_NO_SH 4

/*=============DISPLAY_ON_OFF=============*/
/*CURSOR OR DISPLAY SHIFT BIT NUMBERS*/
#define LCD_DISPLAY_ON_OFF_D_BIT 2
#define LCD_DISPLAY_ON_OFF_C_BIT 1
#define LCD_DISPLAY_ON_OFF_B_BIT 0

/*DISPLAY_ON_OFF Modes*/
#define LCD_CURSOR_MODE_ON 1
#define LCD_CURSOR_MODE_OFF 2
#define LCD_CURSOR_BLINK_MODE_ON 3
#define LCD_CURSOR_BLINK_MODE_OFF 4

/*=============CURSOR OR DISPLAY SHIFT (CODS)=============*/
/*CURSOR OR DISPLAY SHIFT BIT NUMBERS*/
#define LCD_CODS_SC_BIT 3
#define LCD_CODS_RL_BIT 2

/*CURSOR OR DISPLAY SHIFT Modes*/
#define LCD_DISPLAY_SHIFT_CURSOR_LEFT 1
#define LCD_DISPLAY_SHIFT_CURSOR_RIGHT 2
#define LCD_DISPLAY_SHIFT_ALL_LEFT 3
#define LCD_DISPLAY_SHIFT_ALL_RIGHT 4

/*=============FUNCTION_SET=============*/
/*FUNCTION_SET BIT NUMBERS*/
#define LCD_FUNCTION_SET_DL_BIT 4
#define LCD_FUNCTION_SET_N_BIT 3
#define LCD_FUNCTION_SET_F_BIT 2
/*FUNCTION_SET Modes*/
#define LCD_FUNCTION_SET_8BIT 8
#define LCD_FUNCTION_SET_4BIT 4
#define LCD_FUNCTION_SET_1LINE_CONTROL 1
#define LCD_FUNCTION_SET_2LINE_CONTROL 2
#define LCD_FUNCTION_SET_DISPLAY_LINE_5_8 5
#define LCD_FUNCTION_SET_DISPLAY_LINE_5_11 11

#endif