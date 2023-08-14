/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    SPI_CONFIG             ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*SPI data order mode
===========================
            OPTIONS
===========================
1- SPI_DORD_LSB
2- SPI_DORD_MSB
*/
#define SPI_DORD_MODE SPI_DORD_MSB

/*Clock polarity mode
===========================
            OPTIONS
===========================
1- SPI_CLK_POL_LED_RISING
2- SPI_CLK_POL_LED_FALLING
*/
#define SPI_CLK_POLARITY_SEL SPI_CLK_POL_LED_FALLING

/*Clock phase mode
===========================
            OPTIONS
===========================
1- SPI_CLK_PHS_SAMPLE
2- SPI_CLK_PHS_SETUP
*/
#define SPI_CLK_PHASE_SEL SPI_CLK_PHS_SAMPLE

/*SCK Frequency select
===========================
            OPTIONS
===========================
1- SPI_SCK_F_DIV_BY_4
2- SPI_SCK_F_DIV_BY_16
3- SPI_SCK_F_DIV_BY_64
4- SPI_SCK_F_DIV_BY_128
5- SPI_SCK_F_DIV_BY_2
6- SPI_SCK_F_DIV_BY_8
7- SPI_SCK_F_DIV_BY_32
8- SPI_SCK_F_DIV_BY_64_2x
*/
#define SPI_SCK_FREQ_SEL SPI_SCK_F_DIV_BY_16

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

/*Slave Pin (SS) transfer data */
#define SPI_SS_PORT DIO_PORTB
#define SPI_SS_TRANSFER_PIN DIO_PIN3

/*mster / slave it self*/
#define SPI_COMMUNICATION_PORT DIO_PORTB
#define SPI_MOSI_PIN DIO_PIN5
#define SPI_MISO_PIN DIO_PIN6
#define SPI_SCK_PIN DIO_PIN7
#define SPI_SS_PIN DIO_PIN4

#endif
