#pragma once

#include "imgui_window.hpp"

namespace gali
{

class EmulatorWindow : public ImguiWindow
{
private:
    static constexpr gali::ImguiWindowParams imgui_window_params{L"GALI Reader Emulator",    100, 100, 1280, 800,
                                                                 {0.0f, 0.55f, 0.60f, 0.60f}};

    void app_window_function() override;

public:
    EmulatorWindow();
    ~EmulatorWindow() = default;
};

} // namespace gali