#pragma once

#include <array>

#include <serial/serial.h>

namespace gali
{

enum EmulatorComPorts
{
    EMULATOR_COM_METER,
    EMULATOR_COM_READER,

    EMULATOR_COM_N_ELEMENTS
};

class EmulatorHalResources
{
private:
public:
    std::array<serial::PortInfo, EMULATOR_COM_N_ELEMENTS> com_port_info;
};

} // namespace gali