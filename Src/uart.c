#include "uart.h"
#include "stm32f030x8.h"

#include <stdio.h>
#include <stdint.h>

/*=========================================================
                Clock Enable Macros
=========================================================*/

#define GPIOAEN        (1U << 17)
#define USART2EN       (1U << 17)

/*=========================================================
                USART Control Bits
=========================================================*/

#define CR1_UE         (1U << 0)
#define CR1_RE         (1U << 2)
#define CR1_TE         (1U << 3)

/*=========================================================
                USART Status Bits
=========================================================*/

#define ISR_TXE        (1U << 7)
#define ISR_RXNE       (1U << 5)

/*=========================================================
                Clock Configuration
=========================================================*/

#define SYS_CLK        8000000U
#define BAUDRATE       115200U

/*=========================================================
                Private Function Prototype
=========================================================*/

static void UART2_SetBaudRate(uint32_t baudrate);

/*=========================================================
                    UART Initialization
=========================================================*/

void UART2_Init(void)
{
    /* Enable GPIOA Clock */
    RCC->AHBENR |= GPIOAEN;

    /*-----------------------------------------
      PA2 -> USART2_TX
    -----------------------------------------*/

    GPIOA->MODER &= ~(3U << 4);
    GPIOA->MODER |=  (2U << 4);

    GPIOA->AFR[0] &= ~(0xFU << 8);
    GPIOA->AFR[0] |=  (1U << 8);

    /*-----------------------------------------
      PA3 -> USART2_RX
    -----------------------------------------*/

    GPIOA->MODER &= ~(3U << 6);
    GPIOA->MODER |=  (2U << 6);

    GPIOA->AFR[0] &= ~(0xFU << 12);
    GPIOA->AFR[0] |=  (1U << 12);

    /* Enable USART2 Clock */
    RCC->APB1ENR |= USART2EN;

    /* Configure Baud Rate */
    UART2_SetBaudRate(BAUDRATE);

    /* Enable TX and RX */
    USART2->CR1 |= CR1_TE;
    USART2->CR1 |= CR1_RE;

    /* Enable USART2 */
    USART2->CR1 |= CR1_UE;
}

/*=========================================================
                Baud Rate Configuration
=========================================================*/

static void UART2_SetBaudRate(uint32_t baudrate)
{
    USART2->BRR = (SYS_CLK + (baudrate / 2U)) / baudrate;
}

/*=========================================================
                Send One Character
=========================================================*/

void UART2_WriteChar(char ch)
{
    while (!(USART2->ISR & ISR_TXE));

    USART2->TDR = ch;
}

/*=========================================================
                Send String
=========================================================*/

void UART2_WriteString(const char *str)
{
    while (*str)
    {
        UART2_WriteChar(*str++);
    }
}

/*=========================================================
                Receive One Character
=========================================================*/

char UART2_ReadChar(void)
{
    while (!(USART2->ISR & ISR_RXNE));

    return (char)USART2->RDR;
}

/*=========================================================
            printf() Redirection
=========================================================*/

int __io_putchar(int ch)
{
    UART2_WriteChar((char)ch);

    return ch;
}
