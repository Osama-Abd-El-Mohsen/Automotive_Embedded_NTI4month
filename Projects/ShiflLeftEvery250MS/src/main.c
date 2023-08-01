#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "SSD/SSD_interface.h"
#include "LED/LED_interface.h"
#include "SW/SW_interface.h"
// #include "avr/io.h"
int main()
{
  u8 Local_u8PortValue = 0b11111111;
  DIO_u8SetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT);
  while (1)
  {
    for (u8 Local_u8Counter = 1; Local_u8Counter < 9; Local_u8Counter++)
    {

      u8 temp = Local_u8PortValue >> Local_u8Counter;
      for (u8 i = 1; i <= Local_u8Counter; i++)
      {
      SET_BIT(temp, 9 - i);
      }
      
      DIO_u8SetPortValue(DIO_PORTC, temp);
      _delay_ms(20);
      
      if (Local_u8Counter + 1 == 9)
      {
        Local_u8Counter = 0;
      }
    }
  }

  return 0;
}