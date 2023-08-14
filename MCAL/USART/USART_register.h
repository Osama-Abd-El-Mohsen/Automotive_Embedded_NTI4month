/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    USART_REGISTER         ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

/*send recive data 8 bits*/
#define USART_UDR *((volatile u8 *) 0x2C)

/*================ UCSRA ================*/
/*USART Control and Status */
#define USART_UCSRA *((volatile u8 *) 0x2B)

#define USART_UCSRA_RXC     7 /*USART Receive Complete*/
#define USART_UCSRA_TXC     6 /*USART Transmit Complete*/
#define USART_UCSRA_UDRE    5 /*USART Data Register Empty*/
#define USART_UCSRA_FE      4 /*Frame Error*/
#define USART_UCSRA_DOR     3 /*Data OverRun*/
#define USART_UCSRA_PE      2 /*Parity Error*/
#define USART_UCSRA_U2X     1 /*Double the USART Transmission Speed*/
#define USART_UCSRA_MPCM    0 /*Multi-processor Communication Mode*/

/*================ UCSRB ================*/
/*USART Control and Status  */
#define USART_UCSRB *((volatile u8 *) 0x2A)

#define USART_UCSRB_RXCIE    7 /*RX Complete Interrupt Enable*/
#define USART_UCSRB_TXCIE    6 /*TX Complete Interrupt Enable*/
#define USART_UCSRB_UDRIE    5 /*USART Data Register Empty Interrupt Enable*/
#define USART_UCSRB_RXEN     4 /*Receiver Enable*/
#define USART_UCSRB_TXEN     3 /*Transmitter Enable*/
#define USART_UCSRB_UCSZ2    2 /*Character Size*/
#define USART_UCSRB_RXB8     1 /*Receive Data Bit 8*/
#define USART_UCSRB_TXB8     0 /*Transmit Data Bit 8*/

/*================ UCSRC ================*/
/*USART Control and Status  */
#define USART_UCSRC *((volatile u8 *) 0x40)
#define USART_UBRRL *((volatile u8 *) 0x29)

#define USART_UCSRC_URSEL 7 /*Register Select*/
#define USART_UCSRC_UMSEL 6 /*USART Mode Select*/
#define USART_UCSRC_UPM1  5 /*Parity Mode bit 1*/
#define USART_UCSRC_UPM0  4 /*Parity Mode bit 0*/
#define USART_UCSRC_USBS  3 /*Stop Bit Select*/
#define USART_UCSRC_UCSZ1 2 /*Character Size bit 1*/
#define USART_UCSRC_UCSZ0 1 /*Character Size bit 0*/
#define USART_UCSRC_UCPOL 0 /*Clock Polarity*/   



#endif
