#include "imgui_window.hpp"

void test()
{
}

int main(int argc, char const *argv[])
{
    static gali::ImguiWindow emu_win;

    emu_win.run(test);

    return 0;
}
