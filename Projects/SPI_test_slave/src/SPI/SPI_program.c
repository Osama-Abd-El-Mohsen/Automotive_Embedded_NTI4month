/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    SPI_PROGRAM            ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "SPI/SPI_config.h"
#include "SPI/SPI_register.h"
#include "SPI/SPI_private.h"
#include "DIO/DIO_interface.h"
#include "SPI/SPI_interface.h"

u8 Local_State = ZERO;

void SPI_voidMasterInit(void)
{
    Local_State = SPI_MASTER; /*setting state to SLAVE value*/
    /*setting MOSI_MISO_SCK directions*/
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_MOSI_PIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_MISO_PIN, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_SCK_PIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_SS_PIN, DIO_PIN_INPUT); /*input internal pullup*/
    DIO_u8SetPinValue(SPI_COMMUNICATION_PORT, SPI_SS_PIN, DIO_PIN_HIGH);

    DIO_u8SetPinDirection(SPI_SS_PORT, SPI_SS_TRANSFER_PIN, DIO_PIN_OUTPUT);

/*setting SPI data order mode*/
#if SPI_DORD_MODE == SPI_DORD_LSB
    SET_BIT(SPI_SPCR, SPI_SPCR_DORD);
#elif SPI_DORD_MODE == SPI_DORD_MSB
    CLR_BIT(SPI_SPCR, SPI_SPCR_DORD);
#endif

    /*SPI Master/4Slave Select*/
    SET_BIT(SPI_SPCR, SPI_SPCR_MSTR);

/*SPI Clock polarity modect*/
#if SPI_CLK_POLARITY_SEL == SPI_CLK_POL_LED_RISING
    SET_BIT(SPI_SPCR, SPI_SPCR_CPOL);
#elif SPI_CLK_POLARITY_SEL == SPI_CLK_POL_LED_FALLING
    CLR_BIT(SPI_SPCR, SPI_SPCR_CPOL);
#endif

/*SPI Clock phase modect*/
#if SPI_CLK_PHASE_SEL == SPI_CLK_PHS_SAMPLE
    SET_BIT(SPI_SPCR, SPI_SPCR_CPHA);
#elif SPI_CLK_PHASE_SEL == SPI_CLK_PHS_SETUP
    CLR_BIT(SPI_SPCR, SPI_SPCR_CPHA);
#endif

/*SCK Frequency select*/
#if SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_4
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    CLR_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_16
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    CLR_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_64
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    CLR_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_128
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    CLR_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_2
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    SET_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_8
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    SET_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_32
    CLR_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    SET_BIT(SPI_SPSR, SPI_SPSR_SPI2X);
#elif SPI_SCK_FREQ_SEL == SPI_SCK_F_DIV_BY_64_2x
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR0);
    SET_BIT(SPI_SPCR, SPI_SPCR_SPR1);
    SET_BIT(SPI_SPSR, SPI_SPSR_SPI2X);

#endif

    SET_BIT(SPI_SPCR, SPI_SPCR_SPIE); /*Enable SPI interrupt */
    SET_BIT(SPI_SPCR, SPI_SPCR_SPE);  /*Enable SPI */
}

void SPI_voidSlaveInit(void)
{
    Local_State = SPI_SLAVE; /*setting state to SLAVE value*/

    /*setting MOSI_MISO_SCK directions*/
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_MOSI_PIN, DIO_PIN_INPUT);
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_MISO_PIN, DIO_PIN_OUTPUT);
    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_SCK_PIN, DIO_PIN_INPUT);

    DIO_u8SetPinDirection(SPI_COMMUNICATION_PORT, SPI_SS_PIN, DIO_PIN_INPUT); /*input internal pullup*/

/*setting SPI data order mode*/
#if SPI_DORD_MODE == SPI_DORD_LSB
    SET_BIT(SPI_SPCR, SPI_SPCR_DORD);
#elif SPI_DORD_MODE == SPI_DORD_MSB
    CLR_BIT(SPI_SPCR, SPI_SPCR_DORD);
#endif

    /*SPI Master/Slave Select*/
    CLR_BIT(SPI_SPCR, SPI_SPCR_MSTR);

/*SPI Clock polarity modect*/
#if SPI_CLK_POLARITY_SEL == SPI_CLK_POL_LED_RISING
    SET_BIT(SPI_SPCR, SPI_SPCR_CPOL);
#elif SPI_CLK_POLARITY_SEL == SPI_CLK_POL_LED_FALLING
    CLR_BIT(SPI_SPCR, SPI_SPCR_CPOL);
#endif

/*SPI Clock phase modect*/
#if SPI_CLK_PHASE_SEL == SPI_CLK_PHS_SAMPLE
    SET_BIT(SPI_SPCR, SPI_SPCR_CPHA);
#elif SPI_CLK_PHASE_SEL == SPI_CLK_PHS_SETUP
    CLR_BIT(SPI_SPCR, SPI_SPCR_CPHA);
#endif

    SET_BIT(SPI_SPCR, SPI_SPCR_SPIE); /*Enable SPI interrupt */
    SET_BIT(SPI_SPCR, SPI_SPCR_SPE);  /*Enable SPI */
}

u8 SPI_u8Transfer(u8 Copy_u8Data)
{
    if (Local_State == SPI_MASTER)
    {
        DIO_u8SetPinValue(SPI_SS_PORT, SPI_SS_TRANSFER_PIN, DIO_PIN_LOW);
    }

    if ((GET_BIT(SPI_SPSR, SPI_SPSR_WCOL) == 1))
    {
        Local_State = Local_State;
    }

    SPI_SPDR = Copy_u8Data;
    /*wait until SPI interrupt flag is set (transfer or receive is complete)*/
    while ((GET_BIT(SPI_SPSR, SPI_SPSR_SPIF) == ZERO))
        ;
    return SPI_SPDR;
}
