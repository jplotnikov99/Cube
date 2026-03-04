#include "mover.hpp"
#include "puzzle.hpp"
#include <iostream>
#include <ncurses.h>
#include <vector>

// golden ratio
constexpr double GOLD = 1.618;
constexpr double SCALE = 30.;

int main() {

  // Probably only works on linux.
  // Make sure to decrease terminal size to see the full cube.
  // Control rotation with arrow keys.
  using namespace cube;

  // Default cube
  Mover M;
  M.init_cube(SCALE);
  M.control();

  // make your own shape
  // example for dodecahedron below. Comment out above stuff before running below

  /* Mover M;
  std::vector<std::unique_ptr<Vec3D>> corners;

  // inner cube
  corners.push_back(std::make_unique<Vec3D>(SCALE, SCALE, SCALE));
  corners.push_back(std::make_unique<Vec3D>(SCALE, SCALE, -SCALE));
  corners.push_back(std::make_unique<Vec3D>(SCALE, -SCALE, SCALE));
  corners.push_back(std::make_unique<Vec3D>(SCALE, -SCALE, -SCALE));
  corners.push_back(std::make_unique<Vec3D>(-SCALE, SCALE, SCALE));
  corners.push_back(std::make_unique<Vec3D>(-SCALE, SCALE, -SCALE));
  corners.push_back(std::make_unique<Vec3D>(-SCALE, -SCALE, SCALE));
  corners.push_back(std::make_unique<Vec3D>(-SCALE, -SCALE, -SCALE));

  // yz-plane rectangle
  corners.push_back(std::make_unique<Vec3D>(0., SCALE * GOLD, SCALE / GOLD));
  corners.push_back(std::make_unique<Vec3D>(0., SCALE * GOLD, -SCALE / GOLD));
  corners.push_back(std::make_unique<Vec3D>(0., -SCALE * GOLD, SCALE / GOLD));
  corners.push_back(std::make_unique<Vec3D>(0., -SCALE * GOLD, -SCALE / GOLD));

  // xz-plane rectangle
  corners.push_back(std::make_unique<Vec3D>(SCALE / GOLD, 0., SCALE * GOLD));
  corners.push_back(std::make_unique<Vec3D>(SCALE / GOLD, 0., -SCALE * GOLD));
  corners.push_back(std::make_unique<Vec3D>(-SCALE / GOLD, 0., SCALE * GOLD));
  corners.push_back(std::make_unique<Vec3D>(-SCALE / GOLD, 0., -SCALE * GOLD));

  // xz-plane rectangle
  corners.push_back(std::make_unique<Vec3D>(SCALE * GOLD, SCALE / GOLD, 0.));
  corners.push_back(std::make_unique<Vec3D>(SCALE * GOLD, -SCALE / GOLD, 0.));
  corners.push_back(std::make_unique<Vec3D>(-SCALE * GOLD, SCALE / GOLD, 0.));
  corners.push_back(std::make_unique<Vec3D>(-SCALE * GOLD, -SCALE / GOLD, 0.));

  // connect corners/vertices to form lines
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(8)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(4), *corners.at(8)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(9)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(5), *corners.at(9)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(10)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(6), *corners.at(10)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(3), *corners.at(11)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(7), *corners.at(11)));

  M.S->lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(12)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(12)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(4), *corners.at(14)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(6), *corners.at(14)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(13)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(3), *corners.at(13)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(5), *corners.at(15)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(7), *corners.at(15)));

  M.S->lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(16)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(16)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(17)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(3), *corners.at(17)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(4), *corners.at(18)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(5), *corners.at(18)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(6), *corners.at(19)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(7), *corners.at(19)));

  M.S->lines.push_back(std::make_unique<Line>(*corners.at(8), *corners.at(9)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(10), *corners.at(11)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(12), *corners.at(14)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(13), *corners.at(15)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(16), *corners.at(17)));
  M.S->lines.push_back(std::make_unique<Line>(*corners.at(18), *corners.at(19)));

  M.control(); */
  return 0;
}