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
  u8 Local_u8PortValue = 0b00000000;
  u8 temp1 = Local_u8PortValue;
  u8 temp2 = 0b11111111;
  DIO_u8SetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT);
  while (1)
  {
    for (u8 Local_u8Counter = 0; Local_u8Counter < 4; Local_u8Counter++)
    {
      temp1 = temp1;
      SET_BIT(temp1, Local_u8Counter);
      SET_BIT(temp1, 7 - Local_u8Counter);

      DIO_u8SetPortValue(DIO_PORTC, temp1);

      _delay_ms(20);
    }
    temp1 = Local_u8PortValue;
    for (u8 Local_u8Counter = 4; Local_u8Counter > 0; Local_u8Counter--)
    {
      temp2 = temp2;
      CLR_BIT(temp2, 4+(4-Local_u8Counter));
      CLR_BIT(temp2, Local_u8Counter-1);

      DIO_u8SetPortValue(DIO_PORTC, temp2);

      _delay_ms(20);
    }
    temp2 = 0b11111111;
  }
  return 0;
}