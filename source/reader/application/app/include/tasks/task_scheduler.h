#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TASK_SCHEDULER
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TASK_SCHEDULER

#include <stdbool.h>
#include <stdint.h>

#include "tasks/task.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TaskSchedulerProperties
{
    TaskContext **task_array_ptr;
    size_t task_array_size;

} TaskSchedulerProperties;

typedef struct TaskSchedulerContext
{
    const TaskSchedulerProperties *properties;

} TaskSchedulerContext;

void task_scheduler_init(TaskSchedulerContext *);
bool task_scheduler_execute(TaskSchedulerContext *, TaskSleepTime sleep_milliseconds);

#ifdef __cplusplus
}
#endif

#endif
