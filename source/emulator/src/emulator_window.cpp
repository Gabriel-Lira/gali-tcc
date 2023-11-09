#include <imgui.h>

#include "emulator_window.hpp"

gali::EmulatorWindow::EmulatorWindow()
    : imgui_window_params{L"GALI Reader Emulator", 100, 100, 1280, 800, {0.0f, 0.55f, 0.60f, 0.60f}}
    , ImguiWindow(imgui_window_params)
{
}

void gali::EmulatorWindow::app_window_function()
{
    ImGui::Begin("Another Window");
    ImGui::Text("Hello from another window!");
    ImGui::Text("Application FPS %.1f", io->Framerate);
    ImGui::End();
}