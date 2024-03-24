#include "hal/power.h"
#include "hal/timer.h"

#include "app.h"

static void app_call_tasks(AppData *);

void app_init(AppData *app_data, AppResources *app_resources)
{
    timer_init();

    task_manager_init(&app_resources->task_manager_ctx, &app_resources->task_manager_resources);
}

void app_execute(AppData *app_data)
{
    app_call_tasks(app_data);
}

bool app_is_power_down(AppData *app_data)
{
    return power_is_downing();
}

void app_power_down(AppData *app_data)
{
}

void app_auto_execute(AppData *app_data, AppResources *app_resources)
{
    app_init(app_data, app_resources);

    while (!app_is_power_down(app_data))
    {
        app_execute(app_data);
    }

    app_power_down(app_data);
}

static void app_call_tasks(AppData *app_data)
{
    const uint32_t actual_up_time_milliseconds = timer_get_actual_up_time_in_milliseconds();
    uint32_t tasks_diff_time_milliseconds = 0;

    if (actual_up_time_milliseconds > app_data->tasks_last_up_time_milliseconds)
    {
        tasks_diff_time_milliseconds = (actual_up_time_milliseconds - app_data->tasks_last_up_time_milliseconds);
    }

    task_manager_execute_all(tasks_diff_time_milliseconds);
}
