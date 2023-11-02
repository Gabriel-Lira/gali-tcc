#include <stddef.h>

#include "communication/stack/stack.h"

static CommLayerCtx *comm_layer_get_next_to_execute(CommStackCtx *stack_ctx, CommLayerPositionType position_type);

bool comm_stack_process_service(CommStackCtx *stack_ctx, CommLayerPositionType position_type, ServiceMsg *command,
                                ServiceMsg *response)
{
    CommLayerCtx *const layer_ctx_to_execute = comm_layer_get_next_to_execute(stack_ctx, position_type);

    return comm_layer_process_service(layer_ctx_to_execute, COMM_LAYER__SAME, command, response);
}

// TODO: use a doubly linked list
static CommLayerCtx *comm_layer_get_next_to_execute(CommStackCtx *stack_ctx, CommLayerPositionType position_type)
{
    switch (position_type)
    {
    case COMM_LAYER__HIGHER:
        return stack_ctx->highest_layer_ctx;

    case COMM_LAYER__LOWER:
        return stack_ctx->lowest_layer_ctx;

    case COMM_LAYER__SAME:
    default:
        // TODO
        break;
    }

    return NULL;
}
