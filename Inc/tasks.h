#ifndef TASKS_H_
#define TASKS_H_

/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"

/* Task Prototypes */
void LedTask(void *pvParameters);

void LoggerTask(void *pvParameters);

void MonitorTask(void *pvParameters);

#endif
