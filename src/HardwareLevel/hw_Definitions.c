#include "hw_Definitions.h"
#include "stm32f4xx_hal.h"
#include "hw_Definitions.h"
#include "hw_GPIO.h"

/* Private Functions */
hw_Gpio()
{
  gpio_init_output(LED1, GPIOA, GPIO_PIN_5);
}


/* Public Functions */
Hw_Init()
{
  hw_Gpio();
}


