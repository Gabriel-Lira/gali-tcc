#include "com_ports.hpp"

#include <serial/serial.h>

ComPortManager::ComPortManager()
{
    update_com_port_list();
}

void ComPortManager::update_com_port_list()
{
    com_list = serial::list_ports();
}

std::vector<serial::PortInfo> ComPortManager::get_com_port_list()
{
    return com_list;
}

bool operator==(serial::PortInfo &pi1, serial::PortInfo &pi2)
{
    if (pi1.port != pi2.port)
    {
        return false;
    }
    if (pi1.description != pi2.description)
    {
        return false;
    }
    if (pi1.hardware_id != pi2.hardware_id)
    {
        return false;
    }
    return true;
}
