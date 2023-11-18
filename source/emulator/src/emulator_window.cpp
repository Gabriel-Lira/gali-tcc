#include <imgui.h>

#include "com_ports.hpp"
#include "emulator_window.hpp"

gali::EmulatorWindow::EmulatorWindow()
    : ImguiWindow(imgui_window_params)
{
}

void gali::EmulatorWindow::app_window_function()
{
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize({300, 600});
    ImGui::Begin("Input", NULL, default_fixed_window_flags);

    if (ImGui::BeginTabBar("Emulator Tab Bar"))
    {
        if (ImGui::BeginTabItem("Reader"))
        {
            draw_com_port_combo_and_get_selected_info("COM", hal_resources.com_port_info[EMULATOR_COM_READER]);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Meter"))
        {
            draw_com_port_combo_and_get_selected_info("COM", hal_resources.com_port_info[EMULATOR_COM_METER]);
            ImGui::EndTabItem();
        }
    }

    ImGui::EndTabBar();
    ImGui::End();

    ImGui::SetNextWindowPos({0, 600});
    ImGui::SetNextWindowSize({300, 100});
    ImGui::Begin("Emulator", NULL, default_fixed_window_flags);
    if (ImGui::Button("Update COM ports"))
    {
        ComPortManager::update_com_port_list();
    }
    ImGui::Text("Application FPS %.1f", io->Framerate);
    ImGui::End();
}

void gali::EmulatorWindow::draw_com_port_combo_and_get_selected_info(std::string name,
                                                                     serial::PortInfo &selected_port_info)
{
    std::vector<serial::PortInfo> com_port_list = ComPortManager::get_com_port_list();

    int previous_item;
    int current_item;

    if (ImGui::BeginCombo(name.c_str(), selected_port_info.port.c_str()))
    {
        for (size_t i = 0; i < com_port_list.size(); i++)
        {
            serial::PortInfo &port_info_to_test = com_port_list[i];
            const bool is_selected = (selected_port_info == port_info_to_test);

            if (ImGui::Selectable(port_info_to_test.port.c_str(), is_selected))
            {
                selected_port_info = port_info_to_test;
            }

            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}
