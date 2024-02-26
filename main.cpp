#include <iostream>
#include <vector>
#include "shapes.hpp"
#include "mover.hpp"
#include "operators.hpp"

int main()
{
    using namespace cube;

    Mover M;

    M.init_cube(25);

    M.animate();

    return 0;
}