#include "hal/timer.h"

#include "hal/timer.hpp"

gali::reader::Timer::Timer()
    : subscriber(this)
{
}

void timer_init(void)
{
}

uint32_t timer_get_actual_up_time_in_milliseconds(void)
{
    using namespace gali;

    for (reader::Timer &timer : Subscriber<reader::Timer>::get_list_subscribed())
    {
        // TODO: diff from initialized from now
        timer.last_time_miliseconds =
    }
}
