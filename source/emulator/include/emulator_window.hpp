#pragma once

#include "emulator_hal_resorces.hpp"
#include "imgui_window.hpp"

namespace gali
{

class EmulatorWindow : public ImguiWindow
{
private:
    static constexpr ImGuiWindowFlags default_fixed_window_flags{ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                                                                 ImGuiWindowFlags_NoCollapse};

    static constexpr gali::ImguiWindowParams imgui_window_params{L"GALI Reader Emulator",    100, 100, 1280, 800,
                                                                 {0.0f, 0.55f, 0.60f, 0.60f}};
    EmulatorHalResources hal_resources;

    void app_window_function() override;

    void draw_com_port_combo_and_get_selected_info(std::string name, serial::PortInfo &selected_port_info);

public:
    EmulatorWindow();
    ~EmulatorWindow() = default;
};

} // namespace gali