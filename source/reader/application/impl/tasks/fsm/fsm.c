#include "tasks/fsm/fsm.h"

static const Event g_evt_enter_state = {.evt_code = FSM_EVT__ENTER_STATE};
static const Event g_evt_exit_state = {.evt_code = FSM_EVT__EXIT_STATE};

void fsm_init(FsmCtx *fsm_ctx, FsmState initial_state)
{
    fsm_ctx->state = initial_state;
    fsm_dispatch(fsm_ctx, &g_evt_enter_state);
}

void fsm_transit(FsmCtx *fsm_ctx, FsmState next_state)
{
    fsm_dispatch(fsm_ctx, &g_evt_exit_state);
    fsm_ctx->state = next_state;
    fsm_dispatch(fsm_ctx, &g_evt_enter_state);
}

void fsm_dispatch(FsmCtx *fsm_ctx, const Event *evt)
{
    fsm_ctx->state(fsm_ctx, evt);
}
