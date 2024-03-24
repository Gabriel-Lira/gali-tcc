#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TASK_MANAGER
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TASK_MANAGER

#include <stdbool.h>
#include <stdint.h>

#include "tasks/task.h"
#include "tasks/task_scheduler.h"
#include "tasks/types/task_periodic.h"

#ifdef __cplusplus
extern "C" {
#endif

// clang-format off

#define TASK_TABLE(ENTRY, ...)                                                                                              \
    /*    NAME        INITIAL_FUNCTION      INITIAL_STATE                  SLEEP_TIME   N_EVTs*/                                     \
    ENTRY(PERIODIC,   task_periodic_init,   task_periodic_initial_state,   1000,        10, __VA_ARGS__)

// clang-format on

#define EXPAND_AS__TASK_TABLE_TO_ENUM(TASK_NAME, ...) TASK_##TASK_NAME,

#define EXPAND_AS__TASK_TABLE_TO_EVT_QUEUE_OBJECTS(TASK_NAME, TASK_INIT_FUNCT_PTR, TASK_INIT_STATE_FUNCT_PTR,          \
                                                   SLEEP_TIME, N_EVT, ...)                                             \
    Event *TASK_NAME##_evt_queue[N_EVT];

#define EXPAND_AS__TASK_TABLE_TO_MANAGER_PROPERTIES(TASK_NAME, TASK_INIT_FUNCT_PTR, TASK_INIT_STATE_FUNCT_PTR,         \
                                                    SLEEP_TIME, N_EVT, RESOURCES_NAME, ...)                            \
    {.task_properties = {.sleep_milliseconds = SLEEP_TIME},                                                            \
     .task_init_funct_ptr = task_periodic_init,                                                                        \
     .task_initial_state_funct_prt = task_periodic_initial_state,                                                      \
     .task_evt_queue_properties = {.evt_array_ptr = &RESOURCES_NAME##.TASK_NAME##_evt_queue,                           \
                                   .evt_array_size = N_EVT}},

#define TASK_MANAGER_RESOURCES_DEFAULT_VALUE(RESOURCES_NAME)                                                           \
    {                                                                                                                  \
        .manager_properties = {TASK_TABLE(EXPAND_AS__TASK_TABLE_TO_MANAGER_PROPERTIES, RESOURCES_NAME)},               \
        .scheduler_properties = {                                                                                      \
            .task_array_ptr = RESOURCES_NAME.ctx,                                                                      \
            .task_array_size = TASK_N_ELEMENTS                                                                         \
        }                                                                                                              \
    }

typedef enum TaskName
{
    TASK_TABLE(EXPAND_AS__TASK_TABLE_TO_ENUM) TASK_N_ELEMENTS

} TaskName;

typedef struct TaskManagerItemProperties
{
    TaskProperties task_properties;
    EvtQueueProperties task_evt_queue_properties;

    void (*task_init_funct_ptr)(TaskContext *);
    FsmState task_initial_state_funct_prt;

} TaskManagerItemProperties;

typedef struct TaskManagerResources
{
    TaskData data[TASK_N_ELEMENTS];
    TaskContext ctx[TASK_N_ELEMENTS];

    TASK_TABLE(EXPAND_AS__TASK_TABLE_TO_EVT_QUEUE_OBJECTS)

    // TODO: Maybe change this const variables to a struct TaskManagerProperties
    const TaskManagerItemProperties manager_properties[TASK_N_ELEMENTS];
    const TaskSchedulerProperties scheduler_properties;

} TaskManagerResources;

typedef struct TaskManagerContext
{
    TaskSchedulerContext task_scheduler_ctx;

} TaskManagerContext;

void task_manager_init(TaskManagerContext *, TaskManagerResources *);
void task_manager_execute_all(TaskSleepTime tasks_diff_time_milliseconds);

TaskContext *task_manager_get(TaskName);

#ifdef __cplusplus
}
#endif

#endif
