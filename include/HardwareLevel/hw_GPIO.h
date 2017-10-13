#pragma once

#include "hw_Definitions.h"

void gpio_init_output(uint32_t gpio_id, GPIO_TypeDef* port, uint16_t pin );

void gpio_Set(uint32_t gpio_id);

void gpio_Reset(uint32_t gpio_id);
