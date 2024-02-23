#include <iostream>
#include <vector>
#include "3Dvector.hpp"
#include "line.hpp"
#include "frame.hpp"
#include "drawer.hpp"

int main()
{
    using namespace cube;

    Drawer D;

    std::unique_ptr<Line> L = std::make_unique<Line>(0,0,0,-1,70,-20);

    std::unique_ptr<Line> P = std::make_unique<Line>(0,40,-40,-1,74,-10);

    D.draw_line(L);

    D.draw_line(P);

    D.show();

    return 0;
}