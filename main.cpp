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

    std::unique_ptr<Piece> p = std::make_unique<Piece>(1);
    Puzzle puz;

    p->configure(2);
    p->set_y_pos(3);
    p->set_z_pos(4);
    std::cout << puz.check_y_fit(p) << std::endl;
    std::cout << puz.check_z_fit(p) << std::endl;
    
    return 0;
}