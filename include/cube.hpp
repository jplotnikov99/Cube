#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <memory>
#include "3Dvector.hpp"
#include "operators.hpp"

namespace cube
{

    typedef std::vector<std::unique_ptr<Vec3D>> vset;
    typedef std::vector<vset> edges;

    class Cube
    {
    private:
        std::uint16_t CUBE_SIZE; // length of one edge in units of print values
        vset corners;
        edges edge;

    public:
        Cube(std::uint16_t size);
        ~Cube(){};

        void init_corners();
        void print_corners();
        void set_line(Vec3D &p1, Vec3D &p2, vset &line);
        void init_edges();
        void print_line(vset &line);
    };

} // namespace cube
