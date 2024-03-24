#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TASK
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TASK

#include <stdbool.h>
#include <stdint.h>

#include "tasks/fsm/fsm.h"
#include "tasks/queue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t TaskSleepTime;

typedef struct TaskProperties
{
    TaskSleepTime sleep_milliseconds;

} TaskProperties;

typedef struct TaskData
{
    FsmCtx fsm_ctx;
    EvtQueueCtx queue_ctx;
    TaskSleepTime slept_milliseconds;

} TaskData;

typedef struct TaskContext
{
    const TaskProperties *properties;
    TaskData *data;

} TaskContext;

void task_init(TaskContext *, TaskData *, const TaskProperties *);
void task_data_init(TaskData *, const EvtQueueProperties *, FsmState);
void task_sleep(TaskContext *, TaskSleepTime sleep_milliseconds);
bool task_must_wake_up(TaskContext *);
void task_wake_up(TaskContext *);
void task_restart_sleep(TaskContext *);

bool task_execute(TaskContext *, TaskSleepTime sleep_milliseconds);

#ifdef __cplusplus
}
#endif

#endif
