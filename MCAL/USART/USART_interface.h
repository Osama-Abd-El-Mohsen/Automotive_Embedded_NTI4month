/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL                   ***********/
/***********    SWC    :    USART_INTERFACE        ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
u8 USART_u8Receive(void);
void USART_voidSend(u8 Copy_u8Data);
void USART_voidSendString(u8 *Copy_u8Data);
void USART_voidSendFloat( f32 Copy_u32Float, u8 Copy_u8DigitNumber);
void USART_voidSendInt(u32 Copy_u32Int);


#endif