#include "gpio.h"

#define GPIOAEN     (1U << 17)
#define LED_PIN     (1U << 5)

void GPIO_Init(void)
{
    /* Enable GPIOA Clock */
    RCC->AHBENR |= GPIOAEN;

    /* PA5 Output Mode */
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    /* Push Pull */
    GPIOA->OTYPER &= ~LED_PIN;

    /* Medium Speed */
    GPIOA->OSPEEDR &= ~(3U << (5 * 2));
    GPIOA->OSPEEDR |=  (1U << (5 * 2));

    /* No Pull-up Pull-down */
    GPIOA->PUPDR &= ~(3U << (5 * 2));

    LED_OFF();
}

void LED_ON(void)
{
    GPIOA->BSRR = LED_PIN;
}

void LED_OFF(void)
{
    GPIOA->BRR = LED_PIN;
}

void LED_TOGGLE(void)
{
    GPIOA->ODR ^= LED_PIN;
}
