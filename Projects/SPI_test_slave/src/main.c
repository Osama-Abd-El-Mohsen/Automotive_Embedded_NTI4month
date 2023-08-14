#include <LIB/STD_TYPES.h>
#include <LIB/BIT_MATH.h>

#include "DIO/DIO_interface.h"
#include "SPI/SPI_interface.h"
#include "LED/LED_interface.h"
#include "util/delay.h"

void main(void)
{

  SPI_voidSlaveInit();

  // LED_u8TurnOn(DIO_PORTD, DIO_PIN0, LED_U8SOURCE);

  u8 data;
  LCD_voidINIT();

  while (1)
  {
    data = SPI_u8Transfer(5);
    _delay_ms(10);
    LCD_u8SendString(0, 0, "Led State = ");
    if (data == 0)
    {
      LCD_voidGoToRow_Col(1, 0);
      LCD_voidSendData(data + '0');
      LCD_u8SendString(1, 5, "Led off ");
      LED_u8TurnOff(DIO_PORTC, DIO_PIN6, LED_U8SOURCE);
    }

    else if (data == 1)
    {
      LCD_voidGoToRow_Col(1, 0);
      LCD_voidSendData(data + '0');
      LCD_u8SendString(1, 5, "Led on ");
      LED_u8TurnOn(DIO_PORTC, DIO_PIN6, LED_U8SOURCE);
    }
  }
}