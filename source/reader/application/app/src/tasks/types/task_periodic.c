#include "tasks/types/task_periodic.h"

void task_periodic_init(TaskContext *task)
{
}

void task_periodic_initial_state(FsmCtx *fsm, const Event *evt)
{
    switch (evt->evt_code)
    {
    case FSM_EVT__NONE:
        break;

    default:
        break;
    }
}
