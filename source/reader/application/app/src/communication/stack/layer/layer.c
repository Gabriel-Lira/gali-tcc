#include <stddef.h>

#include "communication/stack/layer/layer.h"

static CommLayerCtx *comm_layer_get_next_to_execute(CommLayerCtx *layer_ctx, CommLayerPositionType position_type);

bool comm_layer_process_service(CommLayerCtx *layer_ctx, CommLayerPositionType position_type, ServiceMsg *command,
                                ServiceMsg *response)
{
    CommLayerCtx *const layer_ctx_to_execute = comm_layer_get_next_to_execute(layer_ctx, position_type);

    if (layer_ctx_to_execute == NULL)
    {
        return false;
    }

    return layer_ctx_to_execute->process_service(layer_ctx_to_execute, command, response);
}

static CommLayerCtx *comm_layer_get_next_to_execute(CommLayerCtx *layer_ctx, CommLayerPositionType position_type)
{
    switch (position_type)
    {
    case COMM_LAYER__HIGHER:
        return layer_ctx->higher_layer_ctx;

    case COMM_LAYER__SAME:
        return layer_ctx;

    case COMM_LAYER__LOWER:
        return layer_ctx->lower_layer_ctx;

    default:
        // TODO
        break;
    }

    return NULL;
}