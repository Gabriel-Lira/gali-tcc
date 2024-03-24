#pragma once

#include <vector>

namespace gali
{

template <typename T>
class Subscriber
{
private:
    static std::vector<T &> list;
    T &member;

public:
    Subscriber(T &member)
    {
        list.push_back(member);
    }

    ~Subscriber()
    {
        std::erase_if(list.begin(), list.end(), member);
    }

    static const std::vector<T &> &get_list_subscribed()
    {
        return list;
    }
};

} // namespace gali
