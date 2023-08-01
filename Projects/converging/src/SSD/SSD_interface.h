/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    MCAL				   ***********/
/***********    SWC    :    SSD_INTERFACE 		   ***********/
/***********    Version:    1.00			       ***********/
/*************************************************************/
/*************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_COM_CATHODE 0
#define SSD_COM_ANODE 1

#define SSD_DISNUM0 0
#define SSD_DISNUM1 1
#define SSD_DISNUM2 2
#define SSD_DISNUM3 3
#define SSD_DISNUM4 4
#define SSD_DISNUM5 5
#define SSD_DISNUM6 6
#define SSD_DISNUM7 7
#define SSD_DISNUM8 8
#define SSD_DISNUM9 9


typedef struct
{
    u8 SSD_u8CommonType;
    u8 SSD_u8Port;
    u8 SSD_u8EnablePort;
    u8 SSD_u8EnablePin;
} SSD_t;




u8 SSD_u8Display(SSD_t *Copy_SSD, u8 Copy_u8Value);
u8 SSD_u8Enable(SSD_t *Copy_SSD);
u8 SSD_u8Disable(SSD_t *Copy_SSD);
u8 SSD_u8Clear(SSD_t *Copy_SSD);
#endif