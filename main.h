#ifndef MAIN_H
#define MAIN_H

// #include "types.h"
#include <time.h>
#include "stdint.h"
#include "stdbool.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/driverlib/sysctl.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/driverlib/gpio.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/driverlib/timer.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/driverlib/interrupt.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/inc/hw_memmap.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/inc/hw_types.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/inc/hw_gpio.h"
#include "tm4c123gh6pm.h"
#include "C:/ti/TivaWare_C_Series-2.2.0.295/driverlib/systick.h"
#include "DIO.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

void blink1(uint32 period);
void blink2(uint32 period);
void blink3(uint32 period);

void Systick_Handler(void);

struct Tasks
{
    void (*ptr_task)(uint32);
    uint32 period;
    uint32 priority;
};
extern struct Tasks Task_no[3];
extern uint32 volatile ticks_control;

#endif