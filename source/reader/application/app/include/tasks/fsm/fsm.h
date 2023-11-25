#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_FSM_FSM
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_FSM_FSM

#include "tasks/fsm/evt.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FsmCtx FsmCtx;

typedef void (*FsmState)(FsmCtx *, const Event *);

struct FsmCtx
{
    FsmState state;
};

void fsm_init(FsmCtx *, FsmState initial_state);
void fsm_transit(FsmCtx *, FsmState next_state);
void fsm_dispatch(FsmCtx *, const Event *);

#ifdef __cplusplus
}
#endif

#endif
