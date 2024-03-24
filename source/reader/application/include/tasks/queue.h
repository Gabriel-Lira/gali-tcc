#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_QUEUE
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_QUEUE

#include <stdbool.h>
#include <stddef.h>

#include "tasks/fsm/evt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EvtQueueProperties
{
    Event **evt_array_ptr;
    size_t evt_array_size;

} EvtQueueProperties;

typedef struct EvtQueueCtx
{
    const EvtQueueProperties *properties;
    size_t evt_usage_size;

} EvtQueueCtx;

void evt_queue_init(EvtQueueCtx *, const EvtQueueProperties *);
bool evt_queue_push(EvtQueueCtx *, Event *);
Event *evt_queue_pop(EvtQueueCtx *);

#ifdef __cplusplus
}
#endif

#endif
