#include "tasks/queue.h"

void evt_queue_init(EvtQueueCtx *queue_ctx)
{
    // TODO: ASSERT queue_ctx->properties != null
    // TODO: ASSERT queue_ctx->properties->evt_array_ptr != null

    queue_ctx->evt_usage_size = 0;
}

bool evt_queue_push(EvtQueueCtx *queue_ctx, Event *evt)
{
    if (queue_ctx->evt_usage_size >= queue_ctx->properties->evt_array_size)
    {
        return false;
    }

    queue_ctx->properties->evt_array_ptr[queue_ctx->evt_usage_size++] = evt;

    return true;
}

Event *evt_queue_pop(EvtQueueCtx *queue_ctx)
{
    if (queue_ctx->evt_usage_size == 0)
    {
        static const Event evt_none = {.evt_code = FSM_EVT__NONE};
        return &evt_none;
    }

    return queue_ctx->properties->evt_array_ptr[--queue_ctx->evt_usage_size];
}
