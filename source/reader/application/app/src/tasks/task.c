#include "tasks/task.h"

void task_init(TaskContext *task_ctx)
{
    evt_queue_init(&task_ctx->data->queue_ctx);
    task_restart_sleep(task_ctx);
}

void task_sleep(TaskContext *task_ctx, TaskSleepTime sleep_milliseconds)
{
    if (task_ctx->data->slept_milliseconds < sleep_milliseconds)
    {
        task_ctx->data->slept_milliseconds = 0;
    }
    else
    {
        task_ctx->data->slept_milliseconds -= sleep_milliseconds;
    }
}

bool task_must_wake_up(TaskContext *task_ctx)
{
    return (task_ctx->data->slept_milliseconds == 0);
}

void task_wake_up(TaskContext *task_ctx)
{
    Event *const evt = evt_queue_pop(&task_ctx->data->queue_ctx);

    fsm_dispatch(&task_ctx->data->fsm_ctx, evt);
}

void task_restart_sleep(TaskContext *task_ctx)
{
    task_ctx->data->slept_milliseconds = task_ctx->properties->sleep_milliseconds;
}

bool task_execute(TaskContext *task_ctx, TaskSleepTime sleep_milliseconds)
{
    task_sleep(task_ctx, sleep_milliseconds);

    if (task_must_wake_up(task_ctx))
    {
        task_wake_up(task_ctx);
        task_restart_sleep(task_ctx);
    }
}
