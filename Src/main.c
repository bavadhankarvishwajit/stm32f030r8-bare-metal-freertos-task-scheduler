/******************************************************************************
 * File        : main.c
 * Description : FreeRTOS Project 3
 * Target      : STM32F030R8 (Nucleo)
 ******************************************************************************/

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"
#include "uart.h"
#include "tasks.h"

int main(void)
{
    /*----------------------------------------------------------
                    Hardware Initialization
    ----------------------------------------------------------*/

    GPIO_Init();

    UART2_Init();

    printf("\r\n");
    printf("=========================================\r\n");
    printf("     STM32F030 FreeRTOS Project 3\r\n");
    printf("=========================================\r\n");
    printf("System Boot Successful\r\n\r\n");

    /*----------------------------------------------------------
                    Create Tasks
    ----------------------------------------------------------*/

    BaseType_t status;

    status = xTaskCreate(
                LedTask,
                "LED",
                128,
                NULL,
                2,
                NULL);

    if(status != pdPASS)
    {
        printf("LED Task Creation Failed\r\n");

        while(1);
    }

    status = xTaskCreate(
                LoggerTask,
                "LOGGER",
                128,
                NULL,
                2,
                NULL);

    if(status != pdPASS)
    {
        printf("Logger Task Creation Failed\r\n");

        while(1);
    }

    status = xTaskCreate(
                MonitorTask,
                "MONITOR",
                128,
                NULL,
                1,
                NULL);

    if(status != pdPASS)
    {
        printf("Monitor Task Creation Failed\r\n");

        while(1);
    }

    printf("All Tasks Created Successfully\r\n");
    printf("Starting Scheduler...\r\n\r\n");

    /*----------------------------------------------------------
                    Start Scheduler
    ----------------------------------------------------------*/

    vTaskStartScheduler();

    /*----------------------------------------------------------
                    Should Never Reach Here
    ----------------------------------------------------------*/

    while(1)
    {

    }
}
