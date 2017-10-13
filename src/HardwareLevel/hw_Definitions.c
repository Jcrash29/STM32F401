#include "hw_Definitions.h"
#include "stm32f4xx_hal.h"
#include "hw_Definitions.h"
#include "hw_GPIO.h"
#include "hw_UART.h"

/* Private Functions */
void hw_Gpio()
{
  gpio_init_output(LED1, GPIOA, GPIO_PIN_5);
}


/* Public Functions */
void Hw_Init()
{
  hw_Gpio();
//  Uart_init();
}


