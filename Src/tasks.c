#include "tasks.h"

#include "gpio.h"
#include "uart.h"

#include <stdio.h>

/*-----------------------------------------------------------
                    LED TASK
-----------------------------------------------------------*/
void LedTask(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        LED_ON();
        printf("[LED TASK] LED ON\r\n");

        vTaskDelay(pdMS_TO_TICKS(500));

        LED_OFF();
        printf("[LED TASK] LED OFF\r\n");

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

/*-----------------------------------------------------------
                    LOGGER TASK
-----------------------------------------------------------*/
void LoggerTask(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        printf("[LOGGER TASK] Scheduler Running...\r\n");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

/*-----------------------------------------------------------
                    MONITOR TASK
-----------------------------------------------------------*/
void MonitorTask(void *pvParameters)
{
    (void)pvParameters;

    TickType_t TickCount;

    while (1)
    {
        TickCount = xTaskGetTickCount();

        printf("\r\n");
        printf("=====================================\r\n");
        printf("        MONITOR TASK\r\n");
        printf("=====================================\r\n");
        printf("Tick Count : %lu\r\n", (uint32_t)TickCount);
        printf("System Status : Running\r\n");
        printf("=====================================\r\n\r\n");

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
