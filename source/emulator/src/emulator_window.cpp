#include <imgui.h>

#include "emulator_window.hpp"

gali::EmulatorWindow::EmulatorWindow()
    : ImguiWindow(imgui_window_params)
{
}

void gali::EmulatorWindow::app_window_function()
{
    ImGui::Begin("Another Window");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Application FPS %.1f", io->Framerate);
    ImGui::End();
}