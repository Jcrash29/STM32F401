#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include "hw_Definitions.h"
#include "hw_UART.h"
#include "main.h" /* Let's change this to a hardware location */



void Uart_init()
{
  __USART2_CLK_ENABLE();

  UART_HandleTypeDef huart;
  huart.Instance = USART2;
  huart.Init.BaudRate = 115200;
  huart.Init.WordLength = UART_WORDLENGTH_8B;
  huart.Init.StopBits = UART_STOPBITS_1;
  huart.Init.Parity = UART_PARITY_NONE;
  huart.Init.Mode = UART_MODE_TX_RX;
  huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }


  HAL_UART_Transmit(&huart, (uint8_t*)"TEST BABY TEST", sizeof("TEST BABY TEST"), 0xFFFF);
}
