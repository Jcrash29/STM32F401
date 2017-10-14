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

UART_HandleTypeDef uartStruct[HW_UART_MAX];


void Uart_init()
{
  __USART2_CLK_ENABLE();
}


void Uart_activate(hw_uart_id_t uartID, USART_TypeDef * uartNumber)
{
  Uart_init();

  uartStruct[uartID].Instance = uartNumber;
  uartStruct[uartID].Init.BaudRate = 115200;
  uartStruct[uartID].Init.WordLength = UART_WORDLENGTH_8B;
  uartStruct[uartID].Init.StopBits = UART_STOPBITS_1;
  uartStruct[uartID].Init.Parity = UART_PARITY_NONE;
  uartStruct[uartID].Init.Mode = UART_MODE_TX_RX;
  uartStruct[uartID].Init.HwFlowCtl = UART_HWCONTROL_NONE;
  uartStruct[uartID].Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&uartStruct[uartID]) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}


int uprintf(hw_uart_id_t uartID, const char* format, ...)
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
      ret = HAL_UART_Transmit(&uartStruct[uartID], (uint8_t*)buf, (size_t)ret, 0xFFFF);
    }

  va_end (ap);
  return ret;
}

