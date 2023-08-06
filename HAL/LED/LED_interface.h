/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL                    ***********/
/***********    SWC    :    LED_INTERFACE          ***********/
/***********    Version:    1.00                   ***********/
/*************************************************************/
/*************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_U8SINK 0
#define LED_U8SOURCE 1

/*************************************************************/
/**    Description :  Turnning on and off LED (one LED)     **/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  LedPort,LedPin,LedType                **/
/**    Options     :                                        **/
/**                 1-LED_U8SINK                            **/
/**                 2-LED_U8SOURCE                          **/
/*************************************************************/
u8 LED_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Type);
u8 LED_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Type);

/*************************************************************/
/**    Description :  Turnning on and off LED (Port of LEDS)**/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  LedPort,LedPin,LedType                **/
/**    Options     :                                        **/
/**                 1-LED_U8SINK                            **/
/**                 2-LED_U8SOURCE                          **/
/*************************************************************/
u8 LED_u8PortTurnOn(u8 Copy_u8Port,u8 Copy_u8Type);
u8 LED_u8PortTurnOff(u8 Copy_u8Port,u8 Copy_u8Type);

#endif