#pragma once

namespace gali
{

class EmulatorWindow
{
private:
public:
    EmulatorWindow(void (&app_function)());
    ~EmulatorWindow();
};

} // namespace gali