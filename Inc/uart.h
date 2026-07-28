#ifndef UART_H_
#define UART_H_

#include <stdint.h>

/* Initialization */
void UART2_Init(void);

/* Transmit Functions */
void UART2_WriteChar(char ch);
void UART2_WriteString(const char *str);

/* Receive Function (for future projects) */
char UART2_ReadChar(void);

#endif
