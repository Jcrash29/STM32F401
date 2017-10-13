#pragma once

typedef enum{
  LED1 = 0,
  UART2TX,
  UART2RX,
  HW_GPIO_MAX,
} hw_gpio_id_t;

void Hw_Init();
