/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    SPI_REGISTER           ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

/*================ SPCR ================*/
/*SPI Control and Status */
#define SPI_SPCR *((volatile u8 *) 0x2D)

#define SPI_SPCR_SPIE    7 /*SPI Interrupt Enable*/
#define SPI_SPCR_SPE     6 /*SPI Enable*/
#define SPI_SPCR_DORD    5 /*SPI Data Order*/
#define SPI_SPCR_MSTR    4 /*SPI Master/Slave Select*/
#define SPI_SPCR_CPOL    3 /*SPI Clock Polarity*/
#define SPI_SPCR_CPHA    2 /*SPI Clock Phase*/
#define SPI_SPCR_SPR1    1 /*SPI Clock Rate Select BIT 1*/
#define SPI_SPCR_SPR0    0 /*SPI Clock Rate Select BIT 0*/

/*================ SPCR ================*/
/*SPI Status Register */
#define SPI_SPSR *((volatile u8 *) 0x2E)

#define SPI_SPSR_SPIF    7 /*SPI Interrupt Flag*/
#define SPI_SPSR_WCOL    6 /*SPI Write COLlision Flag*/
#define SPI_SPSR_SPI2X   0 /*SPI Double Speed Bit*/

/*================ SPDR ================*/
/*SPI Data Register */
#define SPI_SPDR *((volatile u8 *) 0x2F)


#endif
