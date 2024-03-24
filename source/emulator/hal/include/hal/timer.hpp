#pragma once

#include "utils/subscriber.hpp"
#include <chrono>

namespace gali
{

namespace reader
{

class Timer
{
private:
    gali::Subscriber<gali::reader::Timer> subscriber;

public:
    std::chrono::microseconds last_time_miliseconds;

    Timer();
    ~Timer() = default;
};

} // namespace reader

} // namespace gali
