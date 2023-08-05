/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL				       ***********/
/***********    SWC    :    KPD_CONFIG_H 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/*this value will be return if not pressed*/
#define KPD_NO_PRESSED_KEY 'N'

/*
Options :
KPD_PORTA
KPD_PORTB
KPD_PORTC
KPD_PORTD
*/
#define KPD_PORT DIO_PORTC
#define KPD_COL0 DIO_PIN0
#define KPD_COL1 DIO_PIN1
#define KPD_COL2 DIO_PIN2
#define KPD_COL3 DIO_PIN3


/*
Options :
DIO_PIN0
DIO_PIN1
DIO_PIN2
DIO_PIN3
DIO_PIN4
DIO_PIN5
DIO_PIN6
DIO_PIN7
*/
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