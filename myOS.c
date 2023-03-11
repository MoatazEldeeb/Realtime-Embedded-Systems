
#include "myOS.h"
#include "main.h"

void sort_tasks(struct Tasks *tasks, int num_tasks)
{
  for (uint32 i = 0; i < num_tasks - 1; i++)
  {
    uint32 min_idx = i;
    for (uint32 j = i + 1; j < num_tasks; j++)
    {
      if (tasks[j].priority > tasks[min_idx].priority)
      {
        min_idx = j;
      }
    }
    if (min_idx != i)
    {
      struct Tasks temp = tasks[i];
      tasks[i] = tasks[min_idx];
      tasks[min_idx] = temp;
    }
  }
}

void OS_sched(void)
{
  struct Tasks tasksToBeRun[3];
  uint32 num_tasks_to_run = 0;
  for (uint32 i = 0; i < 3; i++)
  {
    if ((ticks_control % Task_no[i].period) == 0 && ticks_control !=0)
    {
      tasksToBeRun[num_tasks_to_run] = Task_no[i];
      num_tasks_to_run++;
    }
  }
  if (num_tasks_to_run > 0)
  {
    sort_tasks(tasksToBeRun, num_tasks_to_run);
  }

  for (uint32 i = 0; i < num_tasks_to_run; i++)
  {
    tasksToBeRun[i].ptr_task(tasksToBeRun[i].period);
  }

  // Tasks_no[i].ptr_task(myStruct[i].period);
}
