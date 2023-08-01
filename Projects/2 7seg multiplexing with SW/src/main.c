#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "SSD/SSD_interface.h"
#include "LED/LED_interface.h"
#include "SW/SW_interface.h"
// #include "avr/io.h"

/*config SDD1 , SSD2 , SW1 and SW2*/
SSD_t SSD2 =
    {
        SSD_COM_CATHODE,
        DIO_PORTC,
        DIO_PORTD,
        DIO_PIN2};
SSD_t SSD1 =
    {
        SSD_COM_CATHODE,
        DIO_PORTC,
        DIO_PORTD,
        DIO_PIN3};

SW_T SW1 =
    {
        DIO_PORTD,
        DIO_PIN5,
        SW_U8INTERNAL_PULL_UP,
        SW_U8NOT_SELF_LOCKING};
SW_T SW2 =
    {
        DIO_PORTD,
        DIO_PIN6,
        SW_U8INTERNAL_PULL_UP,
        SW_U8NOT_SELF_LOCKING};

int main()
{
  /*clearing ssd1 and ssd2*/
  SSD_u8Clear(&SSD1);
  SSD_u8Clear(&SSD2);
  u8 Local_u8Switch1Value, Local_u8Switch2Value;
  u8 Local_u8SSD1_Counter = 0, Local_u8SSD2_Counter = 0;

  while (1)
  {
    /*getting switches states*/
    SW_u8StatePressed(&SW1, &Local_u8Switch1Value);
    SW_u8StatePressed(&SW2, &Local_u8Switch2Value);

    /*check if sw1 is pressed*/
    if (Local_u8Switch1Value == SW_PRESSED)
    {
      /*checking 99 state reset to 00*/
      if (Local_u8SSD1_Counter == 9 && Local_u8SSD2_Counter == 9)
      {
        Local_u8SSD1_Counter = -1;
        Local_u8SSD2_Counter = 0;
      }
      /*increment  counter1*/
      Local_u8SSD1_Counter++;
      /*check if counter 1 put of range(bigger than 9)*/
      if (Local_u8SSD1_Counter == 10)
      {
        /*increment counter 2 and resetting counter 1 EX : counter2= 1,counter1=0 (10)*/
        Local_u8SSD2_Counter++;
        Local_u8SSD1_Counter = 0;
      }
    }

    else if (Local_u8Switch2Value == SW_PRESSED)
    {
      /*checking 00 state reset to 99*/
      if (Local_u8SSD2_Counter == 0 && Local_u8SSD1_Counter == 0)
      {
        Local_u8SSD2_Counter = 9;
        Local_u8SSD1_Counter = 10;
      }

      if (Local_u8SSD1_Counter == 0 && Local_u8SSD2_Counter != 0)
      {
        Local_u8SSD2_Counter--;
        Local_u8SSD1_Counter = 9;
        Local_u8SSD1_Counter++;
      }
      Local_u8SSD1_Counter--;
    }

    /*displaying values on SSD and SSD2*/
    SSD_u8Disable(&SSD2);
    SSD_u8Enable(&SSD1);
    SSD_u8Display(&SSD1, Local_u8SSD1_Counter);
    _delay_ms(5);
    SSD_u8Disable(&SSD1);
    SSD_u8Enable(&SSD2);
    SSD_u8Display(&SSD2, Local_u8SSD2_Counter);
    _delay_ms(5);
    SSD_u8Enable(&SSD1);
    SSD_u8Enable(&SSD2);
  }
  return 0;
}