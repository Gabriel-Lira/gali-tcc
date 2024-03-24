#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_STACK_LAYER_LAYER
#define SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_STACK_LAYER_LAYER

#include <stdbool.h>

#include "communication/stack/layer/layer_position_type.h"
#include "communication/stack/service/services.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CommLayerCtx CommLayerCtx;

struct CommLayerCtx
{
    CommLayerCtx *higher_layer_ctx;
    CommLayerCtx *lower_layer_ctx;

    bool (*process_service)(CommLayerCtx *own_layer, ServiceMsg *command, ServiceMsg *response);
};

bool comm_layer_process_service(CommLayerCtx *, CommLayerPositionType, ServiceMsg *command, ServiceMsg *response);

#ifdef __cplusplus
}
#endif

#endif