#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx_hal.h"

void gpio_init()
{
  //Enable the Clock for Port A
  __GPIOA_CLK_ENABLE();

  //Create a Structure for initializing the pins
  GPIO_InitTypeDef GPIO_InitStructure;

  // Configure pin in output push/pull mode Blinking LED
  GPIO_InitStructure.Pin = GPIO_PIN_5;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}







