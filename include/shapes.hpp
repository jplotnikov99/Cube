#pragma once
#include <cassert>
#include <vector>
#include <memory>
#include "line.hpp"

namespace cube
{
    class Shapes
    {
    private:
    public:
        std::vector<std::unique_ptr<Line>> lines;

        size_t get_N_lines();

        void cube(const double &size);

        void pyramid(const double &base, const double &height);

        void rotate(const double &angle, Vec3D &rot_axis);

        

        Shapes(){};
        ~Shapes(){};
    };

} // namespace cube
