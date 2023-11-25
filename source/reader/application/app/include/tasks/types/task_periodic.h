#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TYPES_TASK_PERIODIC
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_TYPES_TASK_PERIODIC

#include "tasks/task.h"

#ifdef __cplusplus
extern "C" {
#endif

void task_periodic_init(TaskContext *);
void task_periodic_initial_state(FsmCtx *, const Event *);

#ifdef __cplusplus
}
#endif

#endif
