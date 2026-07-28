# stm32f030r8-bare-metal-freertos-task-scheduler

A complete bare-metal implementation of FreeRTOS on the STM32F030R8 Nucleo board without using STM32 HAL, LL drivers, or CubeMX.

This project demonstrates how to integrate the FreeRTOS kernel into a completely register-level STM32 firmware while implementing GPIO and UART drivers from scratch.

---

## Features

- Bare-metal STM32 programming
- Register-level peripheral programming
- FreeRTOS Kernel integration
- GPIO driver
- UART2 driver
- Multi-task scheduling
- LED control using tasks
- UART task monitoring
- Idle Hook
- Stack Overflow Hook
- Malloc Failed Hook
- Static startup code
- No HAL
- No CubeMX
- No LL Drivers

---

## Hardware

- STM32 Nucleo-F030R8
- STM32F030R8T6 (ARM Cortex-M0)
- ST-Link V2-1

---

## Software

- STM32CubeIDE
- GNU ARM Toolchain
- FreeRTOS Kernel

---

## Project Structure

```
Project
│
├── Inc
│   ├── FreeRTOSConfig.h
│   ├── gpio.h
│   ├── uart.h
│   ├── tasks.h
│   └── hooks.h
│
├── Src
│   ├── main.c
│   ├── gpio.c
│   ├── uart.c
│   ├── tasks.c
│   ├── hooks.c
│   ├── system.c
│   ├── syscalls.c
│   └── sysmem.c
│
├── Startup
│   └── startup_stm32f030r8tx.s
│
├── FreeRTOS
│   ├── include
│   ├── portable
│   ├── tasks.c
│   ├── queue.c
│   ├── list.c
│   ├── timers.c
│   ├── event_groups.c
│   └── stream_buffer.c
│
└── STM32F030R8TX_FLASH.ld
```

---

## Implemented Drivers

### GPIO Driver

- GPIO Clock Enable
- PA5 Configuration
- LED ON
- LED OFF
- LED Toggle

---

### UART Driver

Implemented completely using registers.

Features

- USART2 TX
- 115200 Baud
- printf() redirection
- Blocking transmission

Pin Configuration

| Peripheral | Pin |
|------------|-----|
| USART2 TX | PA2 |

---

## FreeRTOS Tasks

### Task 1

- Turns LED ON
- Prints status over UART
- Delays for 500 ms

### Task 2

- Turns LED OFF
- Prints status over UART
- Delays for 500 ms

---

## UART Output

```
Task 1 Running
Task 2 Running
Task 1 Running
Task 2 Running
...
```

---

## LED Output

The onboard LED connected to PA5 continuously blinks as Task1 and Task2 alternate execution under the FreeRTOS scheduler.

---

## FreeRTOS Configuration

- Preemptive Scheduling
- Time Slicing
- Tick Rate = 1000 Hz
- Heap_4 Memory Allocator
- Stack Overflow Detection
- Malloc Failed Hook
- Idle Hook Enabled

---

## Learning Objectives

This project demonstrates:

- ARM Cortex-M0 startup sequence
- Scheduler startup
- Context switching
- Task creation
- Task priorities
- Task delay
- SysTick usage
- PendSV usage
- Cooperative vs Preemptive scheduling
- Register-level peripheral programming
- FreeRTOS kernel integration

---

## Build

Build successfully using

STM32CubeIDE

```
Build Finished
0 Errors
1 Warning (FreeRTOS internal warning)
```

---

## Future Work

- Binary Semaphores
- Counting Semaphores
- Mutex
- Queues
- Event Groups
- Software Timers
- Interrupt handling
- UART Receive Interrupt
- DMA
- Low Power Modes

---

## Repository Purpose

This repository is part of my journey to learn embedded systems and RTOS development from scratch using only bare-metal programming techniques.

The goal is to deeply understand how FreeRTOS works internally instead of relying on STM32 HAL or CubeMX generated code.

---

## Author

**Vishwajit Mahesh Bavadhankar**

Embedded Systems | Firmware Development | FreeRTOS | ARM Cortex-M | IoT | Bare-Metal Programming
