#pragma once

void Uart_init();


int
uprintf(UART_HandleTypeDef handle, const char* format, ...);
