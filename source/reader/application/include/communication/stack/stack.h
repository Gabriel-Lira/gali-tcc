#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_STACK_STACK
#define SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_STACK_STACK

#include "communication/stack/layer/layer.h"
#include "communication/stack/layer/layer_position_type.h"
#include "communication/stack/service/services.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CommStackCtx
{
    CommLayerCtx *highest_layer_ctx;
    CommLayerCtx *lowest_layer_ctx;

} CommStackCtx;

bool comm_stack_process_service(CommStackCtx *, CommLayerPositionType, ServiceMsg *command, ServiceMsg *response);

#ifdef __cplusplus
}
#endif

#endif