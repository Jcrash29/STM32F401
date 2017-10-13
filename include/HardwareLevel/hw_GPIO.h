#pragma once

#include "hw_Definitions.h"
#include "stm32f4xx_hal.h"

void gpio_init_output(hw_gpio_id_t gpio_id, GPIO_TypeDef* port, uint16_t pin );

void gpio_Set(hw_gpio_id_t gpio_id);

void gpio_Reset(hw_gpio_id_t gpio_id);
