#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include "hw_Definitions.h"
#include "hw_UART.h"
#include "main.h" /* Let's change this to a hardware location */


#ifndef OS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE
#define OS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE (128)
#endif

  UART_HandleTypeDef huart;


void Uart_init()
{
  __USART2_CLK_ENABLE();


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


  HAL_UART_Transmit(&huart, (uint8_t*)"TEST BABY TEST\n\r", sizeof("TEST BABY TEST"), 0xFFFF);
  uprintf(huart, "TEST 2 BABY\n\r");
  uprintf(huart, "Test %d BABY\n\r", 3);
}


int
uprintf(UART_HandleTypeDef  handle, const char* format, ...)
{
  int ret;
  va_list ap;

  va_start (ap, format);

  // TODO: rewrite it to no longer use newlib, it is way too heavy

  static char buf[OS_INTEGER_TRACE_PRINTF_TMP_ARRAY_SIZE];

  // Print to the local buffer
  ret = vsnprintf (buf, sizeof(buf), format, ap);
  if (ret > 0)
    {
      // Transfer the buffer to the device
      ret = HAL_UART_Transmit(&huart, (uint8_t*)buf, (size_t)ret, 0xFFFF);
    }

  va_end (ap);
  return ret;
}

