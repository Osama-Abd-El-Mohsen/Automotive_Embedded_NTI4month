/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL                    ***********/
/***********    SWC    :    LCD_CONFIG             ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

/*Preprossesor file guard*/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*INIT LCD
===========================
        LCD_BIT_MODE 
        OPTIONS 
===========================
1- LCD_FUNCTION_SET_8BIT
2- LCD_FUNCTION_SET_4BIT

===========================
        LCD_LINE_MODE OPTIONS 
===========================
1- LCD_FUNCTION_SET_1LINE_CONTROL
2- LCD_FUNCTION_SET_2LINE_CONTROL

===========================
        LCD_DISPLAY_LINE_MODE
        OPTIONS 
===========================
1- LCD_FUNCTION_SET_DISPLAY_LINE_5_8
2- LCD_FUNCTION_SET_DISPLAY_LINE_5_11
*/
#define LCD_BIT_MODE  LCD_FUNCTION_SET_8BIT
#define LCD_LINE_MODE  LCD_FUNCTION_SET_2LINE_CONTROL
#define LCD_DISPLAY_LINE_MODE  LCD_FUNCTION_SET_DISPLAY_LINE_5_8

/*Confgi Data & Controll Ports And Bins
===========================
        PORT OPTIONS 
===========================
1- DIO_PORTA
2- DIO_PORTB
3- DIO_PORTC
4- DIO_PORTD
===========================
        PINS OPTIONS
===========================
1- DIO_PIN0
2- DIO_PIN1
3- DIO_PIN2
4- DIO_PIN3
5- DIO_PIN4
6- DIO_PIN5
7- DIO_PIN6
8- DIO_PIN7
*/

#define LCD_CONTROLL_PORT DIO_PORTA
#define LCD_RS_BIN DIO_PIN0
#define LCD_RW_BIN DIO_PIN1
#define LCD_ENABLE_BIN DIO_PIN2

#define LCD_DATA_PORT DIO_PORTB

#endif