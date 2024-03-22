#include <iostream>
#include <vector>
#include <ncurses.h>
#include "mover.hpp"
#include "puzzle.hpp"

int main()
{
    using namespace cube;

    // Mover M;
    // M.init_cube(30.971);
    // M.control();

    Puzzle puz;

    puz.forward_track();
    //puz.print();
    return 0;
}