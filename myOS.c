
#include "myOS.h"
#include "main.h"
void OS_sched(void)
{
    for (uint32 i = 0; i < 3; i++)
    {
      Task_no[i].ptr_task(Task_no[i].period);
    }
    // Task_no[i].ptr_task(myStruct[i].period);
  
}
