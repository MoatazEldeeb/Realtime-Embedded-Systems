#include "main.h"
#include "myOS.h"

uint32 start;
uint32 ticks = 1U;
struct Tasks Task_no[3];

uint32 volatile ticks_control;
void Systick_Handler(void)
{
  ++ticks_control;
}
void blink1(uint32 period)
{

  GPIO_PORTF_DATA_R = LED_RED;
  __asm("CPSID  I");
  start = ticks_control;
  __asm("CPSIE  I");
  while ((ticks_control - start) < ticks)
  {
  }
  GPIO_PORTF_DATA_R &= ~LED_RED;
  __asm("CPSID  I");
  start = ticks_control;
  __asm("CPSIE  I");
  while ((ticks_control - start) < ticks)
  {
  }
}

void blink2(uint32 period)
{

  GPIO_PORTF_DATA_R = LED_BLUE;
  __asm("CPSID  I");
  start = ticks_control;
  __asm("CPSIE  I");
  while ((ticks_control - start) < ticks)
  {
  }
  GPIO_PORTF_DATA_R &= ~LED_BLUE;
  __asm("CPSID  I");
  start = ticks_control;
  __asm("CPSIE  I");
  while ((ticks_control - start) < ticks)
  {
  }
}

void blink3(uint32 period)
{

  GPIO_PORTF_DATA_R = LED_GREEN;
  __asm("CPSID  I");
  start = ticks_control;
  __asm("CPSIE  I");
  while ((ticks_control - start) < ticks)
  {
  }
  GPIO_PORTF_DATA_R &= ~LED_GREEN;
  __asm("CPSID  I");
  start = ticks_control;
  __asm("CPSIE  I");
  while ((ticks_control - start) < ticks)
  {
  }
}

int main()
{
  // PortFInit();
  SYSCTL_RCGCGPIO_R = 0x20U;
  GPIO_PORTF_DIR_R = 0X0EU;
  GPIO_PORTF_DEN_R = 0X0EU;
  NVIC_ST_RELOAD_R = 0XFFFFFFU;
  NVIC_ST_CTRL_R = 0x7U;

  Task_no[0].ptr_task = &blink1;
  Task_no[0].period = 5;
  Task_no[0].priority = 1;

  Task_no[1].ptr_task = &blink2;
  Task_no[1].period = 10;
  Task_no[1].priority = 2;

  Task_no[2].ptr_task = &blink3;
  Task_no[2].period = 20;
  Task_no[2].priority = 3;

  while (1)
  {
    __asm("CPSID  I");
    OS_sched();
    __asm("CPSIE  I");
  }
}
