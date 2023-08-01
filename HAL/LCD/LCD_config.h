/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL				       ***********/
/***********    SWC    :    LCD_CONFIG_H     		***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*INIT LCD
LCD_BIT_MODE 
Options :

LCD_FUNCTION_SET_8BIT
LCD_FUNCTION_SET_4BIT

LCD_LINE_MODE
Options:
LCD_FUNCTION_SET_1LINE_CONTROL
LCD_FUNCTION_SET_2LINE_CONTROL

LCD_DISPLAY_LINE_MODE
Oprtions:
LCD_FUNCTION_SET_DISPLAY_LINE_5_8
LCD_FUNCTION_SET_DISPLAY_LINE_5_11
*/
#define LCD_BIT_MODE  LCD_FUNCTION_SET_8BIT
#define LCD_LINE_MODE  LCD_FUNCTION_SET_2LINE_CONTROL
#define LCD_DISPLAY_LINE_MODE  LCD_FUNCTION_SET_DISPLAY_LINE_5_8

/*Confgi Data & Controll Ports And Bins
PORT options:
DIO_PORTA
DIO_PORTB
DIO_PORTC
DIO_PORTD
*/

#define LCD_CONTROLL_PORT DIO_PORTC
#define LCD_RS_BIN DIO_PIN0
#define LCD_RW_BIN DIO_PIN1
#define LCD_ENABLE_BIN DIO_PIN2

#define LCD_DATA_PORT DIO_PORTD

#endif