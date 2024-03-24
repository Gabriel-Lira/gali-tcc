#include "tasks/task_manager.h"

static TaskManagerContext *g_task_manager_ctx;

void task_manager_init(TaskManagerContext *task_manager_ctx, TaskManagerResources *task_manager_resources)
{
    for (size_t i = 0; i < TASK_N_ELEMENTS; i++)
    {
        TaskData *const task_data = &task_manager_resources->data[i];
        TaskContext *const task_ctx = &task_manager_resources->ctx[i];
        const TaskManagerItemProperties *const item_properties = &task_manager_resources->manager_properties[i];

        task_data_init(task_data, &item_properties->task_evt_queue_properties,
                       item_properties->task_initial_state_funct_prt);

        task_init(task_ctx, task_data, &item_properties->task_properties);
    }

    task_scheduler_init(&task_manager_ctx->task_scheduler_ctx, &task_manager_resources->scheduler_properties);

    g_task_manager_ctx = task_manager_ctx;
}

void task_manager_execute_all(TaskSleepTime tasks_diff_time_milliseconds)
{
    task_scheduler_execute(&g_task_manager_ctx->task_scheduler_ctx, tasks_diff_time_milliseconds);
}

TaskContext *task_manager_get(TaskName task_name)
{
    // TODO: ASSERT
    return g_task_manager_ctx->task_scheduler_ctx.properties->task_array_ptr[task_name];
}
