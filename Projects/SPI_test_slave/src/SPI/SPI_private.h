/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    SPI_PRIVATE            ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_DORD_LSB 0
#define SPI_DORD_MSB 1

#define SPI_CLK_POL_LED_RISING    0
#define SPI_CLK_POL_LED_FALLING   1

#define SPI_CLK_PHS_SAMPLE    0
#define SPI_CLK_PHS_SETUP     1

#define SPI_SCK_F_DIV_BY_4     0
#define SPI_SCK_F_DIV_BY_16    1
#define SPI_SCK_F_DIV_BY_64    2
#define SPI_SCK_F_DIV_BY_128   3
#define SPI_SCK_F_DIV_BY_2     4
#define SPI_SCK_F_DIV_BY_8     5
#define SPI_SCK_F_DIV_BY_32    6
#define SPI_SCK_F_DIV_BY_64_2x    7

#define SPI_MASTER 1
#define SPI_SLAVE  2

#endif