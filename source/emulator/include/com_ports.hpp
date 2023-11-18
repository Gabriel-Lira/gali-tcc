#pragma once

#include <memory>
#include <string>
#include <vector>

#include <serial/serial.h>

class ComPortManager
{
private:
    inline static std::vector<serial::PortInfo> com_list;

public:
    ComPortManager();
    ~ComPortManager() = default;

    static void update_com_port_list();
    static auto get_com_port_list() -> std::vector<serial::PortInfo>;
};

bool operator==(serial::PortInfo &, serial::PortInfo &);