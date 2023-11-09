#pragma once

#include "imgui_window.hpp"

namespace gali
{

class EmulatorWindow : public ImguiWindow
{
private:
    const ImguiWindowParams imgui_window_params;

    void app_window_function() override;

public:
    EmulatorWindow();
    ~EmulatorWindow() = default;
};

} // namespace gali