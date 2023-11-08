#include "imgui_window.hpp"

void test()
{
}

int main(int argc, char const *argv[])
{
    const gali::ImguiWindowParams emulator_params{L"GALI Reader Emulator", 100, 100, 1280, 800};
    static gali::ImguiWindow emulator_win(emulator_params);

    emulator_win.run(test);

    return 0;
}
