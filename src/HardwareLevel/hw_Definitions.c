#include "hw_Definitions.h"
#include "stm32f4xx_hal.h"
#include "hw_Definitions.h"
#include "hw_GPIO.h"
#include "hw_UART.h"

/* Private Functions */
void hw_Gpio()
{
  Gpio_initOutput(LED1, GPIOA, GPIO_PIN_5);
  Gpio_initAdvanced(UART2TX,GPIOA, GPIO_PIN_2,GPIO_MODE_AF_PP,GPIO_NOPULL,GPIO_SPEED_LOW,GPIO_AF7_USART2);
  Gpio_initAdvanced(UART2RX,GPIOA, GPIO_PIN_3,GPIO_MODE_AF_PP,GPIO_NOPULL,GPIO_SPEED_LOW,GPIO_AF7_USART2);
}

void hw_Uart()
{
  Uart_activate(MAIN, USART2);
}


/* Public Functions */
void Hw_Init()
{
  hw_Gpio();
  hw_Uart();
}


