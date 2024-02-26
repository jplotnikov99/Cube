#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "types.hpp"

namespace cube
{
    typedef std::vector<double> point;
    typedef std::unique_ptr<point> vec3D;

    class Vec3D
    {
    private:
        vec3D vec;
        double len;

    public:
        Vec3D();
        Vec3D(const double &x, const double &y, const double &z);
        Vec3D(point &p);

        double get_x();
        double get_y();
        double get_z();
        point get_point();
        double get_len();

        void set_x(const double &x);
        void set_y(const double &y);
        void set_z(const double &z);
        void set_xyz(const double &x, const double &y, const double &z);

        void normalize();

        void print();

        ~Vec3D()
        {
            //std::cout << "Vec destroyed\n";
        };
    };

} // namespace cube
