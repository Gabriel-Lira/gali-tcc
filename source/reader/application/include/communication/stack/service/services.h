#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_STACK_SERVICE_SERVICES
#define SOURCE_READER_APPLICATION_APP_INCLUDE_COMMUNICATION_STACK_SERVICE_SERVICES

#include "communication/stack/service/service_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ServicePrimitiveType
{
    COMM_SERVICE_TYPE__REQUEST,
    COMM_SERVICE_TYPE__CONFIRM,
    COMM_SERVICE_TYPE__INDICATION,
    COMM_SERVICE_TYPE__RESPONSE,

    COMM_SERVICE_TYPE__N_ELEMENTS,

} ServicePrimitiveType;

typedef struct ServiceMsg
{
    ServiceType type;
    ServicePrimitiveType primitive;

} ServiceMsg;

#ifdef __cplusplus
}
#endif

#endif