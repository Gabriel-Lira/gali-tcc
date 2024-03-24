#ifndef SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_FSM_EVT
#define SOURCE_READER_APPLICATION_APP_INCLUDE_TASKS_FSM_EVT

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Event
{
    int evt_code; // used int to be filled by enum values, like EvtType

} Event;

typedef enum EvtType
{
    FSM_EVT__NONE,
    FSM_EVT__ENTER_STATE,
    FSM_EVT__EXIT_STATE,

    FSM_EVT__N_ELEMENTS,

} EvtType;

#ifdef __cplusplus
}
#endif

#endif
