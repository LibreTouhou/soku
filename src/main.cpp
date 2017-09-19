#include "soku.hpp"

int main(int argc, char *argv[])
{
    Soku test;
    test.initialize(argc, argv);
    test.loop();
    test.deinitialize();
}
