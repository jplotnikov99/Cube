#include <iostream>
#include <vector>
#include <ncurses.h>
#include "mover.hpp"
#include "puzzle.hpp"

int main()
{
    // Probably only works on linux.
    // Make sure to decrease terminal size to see the full cube.
    // Control rotation with arrow keys.
    using namespace cube;

    Mover M;
    M.init_cube(5.);
    M.control();


    return 0;
}