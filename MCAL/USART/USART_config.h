/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    USART_CONFIG           ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*Double USART TR speed ASYNCHRONOUS only
===========================
            OPTIONS
===========================
1- USART_U2X_ENABLE
2- USART_U2X_DISABLE
*/
#define USART_DOUBLE_TR_SPEED USART_U2X_DISABLE

/*Select USART type
===========================
            OPTIONS
===========================
1- USART_SYNCHRONOUS
2- USART_ASYNCHRONOUS
*/
#define USART_TYPE USART_ASYNCHRONOUS

/*Multi Processor
===========================
            OPTIONS
===========================
1- USART_MULTI_PROC_ENABLE
2- USART_MULTI_PROC_DISABLE
*/
#define USART_MULTI_PROC_MODE USART_MULTI_PROC_DISABLE

/*Setting char size
===========================
            OPTIONS
===========================
1- USART_CHAR_SIZE_5BIT
2- USART_CHAR_SIZE_6BIT
3- USART_CHAR_SIZE_7BIT
4- USART_CHAR_SIZE_8BIT
5- USART_CHAR_SIZE_9BIT
*/
#define USART_CHAR_SIZE_SEL USART_CHAR_SIZE_8BIT

/*Setting Parity mode
===========================
            OPTIONS
===========================
1- USART_PARITY_DISABLE
2- USART_PARITY_EVEN
3- USART_PARITY_ODD
*/
#define USART_PARITY_MODE USART_PARITY_DISABLE

/*Stop bit mode
===========================
            OPTIONS
===========================
1- USART_STOP_1BIT
2- USART_STOP_2BIT
*/
#define USART_STOP_MODE USART_STOP_1BIT

/*set freq*/
#define USART_FOSC  8000000
/*set baudrate*/
#define USART_BAUD  9600

#endif