#ifndef SOURCE_READER_HAL_INTERFACE_INCLUDE_HAL_TIMER
#define SOURCE_READER_HAL_INTERFACE_INCLUDE_HAL_TIMER

#include "tasks/task.h"

#ifdef __cplusplus
extern "C" {
#endif

void timer_init(void);

uint32_t timer_get_actual_up_time_in_milliseconds(void);

#ifdef __cplusplus
}
#endif

#endif
