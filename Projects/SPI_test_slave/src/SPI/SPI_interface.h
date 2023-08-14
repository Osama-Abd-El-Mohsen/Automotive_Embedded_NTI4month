/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    SPI_INTERFACE          ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_u8Data);

void SPI_voidSendString(u8 *Copy_u8Data);
void SPI_voidSendFloat(f32 Copy_u32Float, u8 Copy_u8DigitNumber);
void SPI_voidSendInt(u32 Copy_u32Int);

#endif