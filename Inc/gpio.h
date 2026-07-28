#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f030x8.h"

/* PA5 LED */

void GPIO_Init(void);

void LED_ON(void);

void LED_OFF(void);

void LED_TOGGLE(void);

#endif
