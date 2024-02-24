#include <iostream>
#include <vector>
#include "3Dvector.hpp"
#include "line.hpp"
#include "frame.hpp"
#include "drawer.hpp"
#include "operators.hpp"

int main()
{
    using namespace cube;

    Drawer D;

    std::unique_ptr<Line> L = std::make_unique<Line>(0,0,0,0,20,20);

    Vec3D axis(1,0,0);

    //D.draw_line(L);

    L->rotate(M_PI / 2, axis);

    D.draw_line(L);

    D.show();

    return 0;
}