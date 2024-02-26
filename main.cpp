#include <iostream>
#include <vector>
#include <ncurses.h>
#include "shapes.hpp"
#include "mover.hpp"
#include "operators.hpp"

int main()
{
    using namespace cube;

    Mover M;

    M.init_pyramid(50,40);

    M.animate();

    return 0;
}