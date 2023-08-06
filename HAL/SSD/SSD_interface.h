/*************************************************************/
/*************************************************************/
/***********    Author :    Osama Abd EL Mohsen    ***********/
/***********    Layer  :    HAL 				   ***********/
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


/*************************************************************/
/**    Description :  Display value on SSD                  **/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  Takeing SSD_T info struct and value   **/
/**    Options     :                                        **/
/**                 01-SSD_DISNUM0                          **/
/**                 02-SSD_DISNUM1                          **/
/**                 03-SSD_DISNUM2                          **/
/**                 04-SSD_DISNUM3                          **/
/**                 05-SSD_DISNUM4                          **/
/**                 06-SSD_DISNUM5                          **/
/**                 07-SSD_DISNUM6                          **/
/**                 08-SSD_DISNUM7                          **/
/**                 09-SSD_DISNUM8                          **/
/**                 10-SSD_DISNUM9                          **/
/*************************************************************/
u8 SSD_u8Display(SSD_t *Copy_SSD, u8 Copy_u8Value);

/*************************************************************/
/**    Description :  Enable and Disable SSD (multiplexing) **/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  Takeing SSD_T info struct             **/
/*************************************************************/
u8 SSD_u8Enable(SSD_t *Copy_SSD);
u8 SSD_u8Disable(SSD_t *Copy_SSD);

/*************************************************************/
/**    Description :  Clearring SSD                         **/
/**    Return      :  Errorstate                            **/
/**    Parameters  :  Takeing SSD_T info struct             **/
/*************************************************************/
u8 SSD_u8Clear(SSD_t *Copy_SSD);
#endif