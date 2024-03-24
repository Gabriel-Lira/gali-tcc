#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_APP
#define SOURCE_READER_APPLICATION_APP_INCLUDE_APP

#include <stdbool.h>

#include "tasks/task_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CREATE_APP_RESOURCES(APP_RESOURCES_NAME)                                                                       \
    AppResources APP_RESOURCES_NAME = {                                                                                \
        .task_manager_resources = TASK_MANAGER_RESOURCES_DEFAULT_VALUE(APP_RESOURCES_NAME.task_manager_resources)}

typedef struct AppResources
{
    TaskManagerContext task_manager_ctx;
    TaskManagerResources task_manager_resources;

} AppResources;

typedef struct AppData
{
    TaskSleepTime tasks_last_up_time_milliseconds;

} AppData;

void app_init(AppData *, AppResources *);
void app_execute(AppData *);
bool app_is_power_down(AppData *);
void app_power_down(AppData *);

void app_auto_execute(AppData *, AppResources *);

#ifdef __cplusplus
}
#endif

#endif