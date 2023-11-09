#include "imgui_window.hpp"

void test()
{
}

int main(int argc, char const *argv[])
{
    const gali::ImguiWindowParams emulator_params{L"GALI Reader Emulator",     100, 100, 1280, 800,
                                                  {0.0f, 0.55f, 0.60f, 0.60f}, test};
    static gali::ImguiWindow emulator_win(emulator_params);

    emulator_win.run();

    return 0;
}
