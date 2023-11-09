#include "emulator_window.hpp"

int main(int argc, char const *argv[])
{
    static gali::EmulatorWindow emulator_win;

    emulator_win.run();

    return 0;
}
