#include "game.hpp"

int main(int argc, char *argv[])
{
    Game test;
    test.initialize(argc, argv);
    test.loop();
    test.deinitialize();
}
