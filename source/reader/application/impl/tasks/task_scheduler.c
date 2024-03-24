#include "tasks/task_scheduler.h"

void task_scheduler_init(TaskSchedulerContext *scheduler_ctx, const TaskSchedulerProperties *scheduler_properties)
{
    scheduler_ctx->properties = scheduler_properties;
}

bool task_scheduler_execute(TaskSchedulerContext *scheduler_ctx, TaskSleepTime sleep_milliseconds)
{
    for (size_t i = 0; i < scheduler_ctx->properties->task_array_size; i++)
    {
        TaskContext *const task_ctx = scheduler_ctx->properties->task_array_ptr[i];

        task_execute(task_ctx, sleep_milliseconds);
    }
}
