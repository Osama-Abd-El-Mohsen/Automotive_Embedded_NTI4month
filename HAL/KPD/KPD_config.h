/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL			   ***********/
/***********    SWC    :    KPD_CONFIG  	   ***********/
/***********    Version:    1.00		   ***********/
/*************************************************************/
/*************************************************************/


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/*this value will be return if not pressed*/
#define KPD_NO_PRESSED_KEY 'N'

/*
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

#define KPD_PORT DIO_PORTC
#define KPD_COL0 DIO_PIN0
#define KPD_COL1 DIO_PIN1
#define KPD_COL2 DIO_PIN2
#define KPD_COL3 DIO_PIN3

#define KPD_ROW0 DIO_PIN4
#define KPD_ROW1 DIO_PIN5
#define KPD_ROW2 DIO_PIN6
#define KPD_ROW3 DIO_PIN7

/*define keypad buttons*/
#define KPD_COLS 4
#define KPD_ROWS 4

u8 KPD_u8arr[KPD_COLS][KPD_ROWS]={
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'C','0','=','+'}
};
#endif