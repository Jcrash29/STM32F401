#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "hw_Definitions.h"
#include "hw_GPIO.h"

/********** Global ***********/
bool isInitalized = false; /**<Determines if the clocks have been set */


typedef struct {
  uint16_t pin;
  GPIO_TypeDef* port;
}GPIO_packed_t;

GPIO_packed_t gpio_Array[HW_GPIO_MAX];
GPIO_InitTypeDef GPIO_InitStructure;

void gpio_init()
{
  //Enable the Clock for Port A
  __GPIOA_CLK_ENABLE();
}

void gpio_init_output(hw_gpio_id_t gpio_id, GPIO_TypeDef* port, uint16_t pin )
{
  /* Required at the top of all function to initialize the clocks */
  if (isInitalized == false) { gpio_init(); }

  /* Add the gpio info to the array */
  gpio_Array[gpio_id].pin = pin;
  gpio_Array[gpio_id].port = port;

  /* Initialize the Structure */
  GPIO_InitStructure.Pin = pin;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(port, &GPIO_InitStructure);
}


void gpio_Set(hw_gpio_id_t gpio_id)
{
  HAL_GPIO_WritePin(gpio_Array[gpio_id].port, gpio_Array[gpio_id].pin, GPIO_PIN_SET);
}

void gpio_Reset(hw_gpio_id_t gpio_id)
{
  HAL_GPIO_WritePin(gpio_Array[gpio_id].port, gpio_Array[gpio_id].pin, GPIO_PIN_RESET);
}






