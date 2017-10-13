/***** Includes *****/
#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "hw_Definitions.h"
#include "hw_GPIO.h"

/***** Private typedefs *****/
typedef struct {
  uint16_t      pin;  /**< Pin number of the GPIO pin */
  GPIO_TypeDef* port; /**< The Port A-G of the GPIO pin */
}GPIO_packed_t;

/***** Global *****/
bool isInitalized = false; /**<Determines if the clocks have been set */

GPIO_packed_t gpio_Array[HW_GPIO_MAX]; /**< An Array which holds information about each of the GPIO pins */
GPIO_InitTypeDef GPIO_InitStructure; /**< GPIO structure  for initializing GPIO */

/***** Private Function Definitions *****/
void gpio_init();

/***** Private Functions *****/
/**
 * Initialize the Clocks of each of the ports
 */
void gpio_init()
{
  __GPIOA_CLK_ENABLE();

  /* TODO: find a way to start these clocks when a GPIO item gets called with them */
}

/***** Public Functions ******/
/**
 * Take in a GPIO_ID + Port and Pin and set it as an output.
 * The GPIO pin can than be set/reset using the GPIO_ID.
 *
 * @Note:This is setting pins into Pull Up mode. If a different setting is
 * required please use the advanced command
 */
void Gpio_initOutput(hw_gpio_id_t gpio_id, GPIO_TypeDef* port, uint16_t pin )
{
  /* This simply sets most of the defaults for an output */
  Gpio_initAdvanced(gpio_id, port, pin,
		     GPIO_MODE_OUTPUT_PP, GPIO_PULLUP, GPIO_SPEED_FAST, 0);

}

/**
 * Take in a GPIO_ID, and all information required to set a GPIO pin, at which
 * point it can be used using the GPIO_ID
 */
void Gpio_initAdvanced(hw_gpio_id_t gpio_id, GPIO_TypeDef* port, uint16_t pin,
			uint32_t mode, uint32_t pull, uint32_t speed, uint32_t alternate)
{
  /* Required at the top of all function to initialize the clocks */
  if (isInitalized == false) { gpio_init(); }

  /* Add the gpio info to the array */
  gpio_Array[gpio_id].pin = pin;
  gpio_Array[gpio_id].port = port;

  /* Initialize the Structure */
  GPIO_InitStructure.Pin = pin;
  GPIO_InitStructure.Mode = mode;
  GPIO_InitStructure.Pull = pull;
  GPIO_InitStructure.Speed = speed;
  GPIO_InitStructure.Alternate = alternate;
  HAL_GPIO_Init(port, &GPIO_InitStructure);
}

/**
 * Using the GPIO_ID of a pin set to an output, set it HIGH
 */
void Gpio_Set(hw_gpio_id_t gpio_id)
{
  HAL_GPIO_WritePin(gpio_Array[gpio_id].port, gpio_Array[gpio_id].pin, GPIO_PIN_SET);
}

/**
 * Using the GPIO_ID of a pin set to an output, set it LOW
 */
void Gpio_Reset(hw_gpio_id_t gpio_id)
{
  HAL_GPIO_WritePin(gpio_Array[gpio_id].port, gpio_Array[gpio_id].pin, GPIO_PIN_RESET);
}

