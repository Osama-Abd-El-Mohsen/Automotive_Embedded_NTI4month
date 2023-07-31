/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    LIB				       ***********/
/***********    SWC    :    LED_INTERFACE   		***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_U8SINK 0
#define LED_U8SOURCE 1

u8 LED_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Type);
u8 LED_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Type);

u8 LED_u8PortTurnOn(u8 Copy_u8Port,u8 Copy_u8Type);
u8 LED_u8PortTurnOff(u8 Copy_u8Port,u8 Copy_u8Type);

#endif