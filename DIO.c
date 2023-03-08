#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
void DIO_Init_port (uint32 portbase,uint8 port_dir)
{
 //LOCK key
 (*((volatile unsigned long *)(portbase+0x520U))) = GPIO_LOCK_KEY;
 //commit registry
 (*((volatile unsigned long *)(portbase+0x524U))) = 0xFF;
 //port direction
 (*((volatile unsigned long *)(portbase+0x400U))) = port_dir;
 //pull up resistor
 (*((volatile unsigned long *)(portbase+0x510U))) = (~port_dir);
 //digital enabler
 (*((volatile unsigned long *)(portbase+0x51CU)))= 0xFF;
}
void DIO_WritePort(uint32 portbase, uint8 value)
{
 (*((volatile unsigned long *)(portbase)))=value;
}
void DIO_WritePin (uint32 port_num, uint8 pin_num, uint8 value)
{
 if (value == LOGIC_HIGH)
 SET_BIT((*((volatile unsigned long *)(port_num))),pin_num);
 else
 CLEAR_BIT((*((volatile unsigned long *)(port_num))),pin_num);
}
uint8 DIO_ReadPin (uint32 port_num, uint8 pin_num)
{
 return GET_BIT((*((volatile unsigned long *)(port_num))),pin_num);
}
uint8 DIO_ReadPort (uint32 port_num)
{
 return (*((volatile unsigned long *)(port_num)));
}