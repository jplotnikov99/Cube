#include "3Dvector.hpp"

namespace cube
{
    Vec3D::Vec3D()
    {
        vec = std::make_unique<point>();
        vec->push_back(0);
        vec->push_back(0);
        vec->push_back(0);
    }

    Vec3D::Vec3D(const double &x, const double &y, const double &z)
    {
        vec = std::make_unique<point>();
        vec->push_back(x);
        vec->push_back(y);
        vec->push_back(z);
    }

    Vec3D::Vec3D(point &p)
    {
        assert(p.size() == 3);
        vec = std::make_unique<point>(p);
    }

    double Vec3D::get_x()
    {
        return vec->at(0);
    }

    double Vec3D::get_y()
    {
        return vec->at(1);
    }

    double Vec3D::get_z()
    {
        return vec->at(2);
    }

    double Vec3D::get_len()
    {
        return sqrt(vec->at(0) * vec->at(0) + vec->at(1) * vec->at(1) + vec->at(2) * vec->at(2));
    }

    void Vec3D::set_x(const double &x)
    {
        vec->at(0) = x;
    }

    void Vec3D::set_y(const double &y)
    {
        vec->at(1) = y;
    }

    void Vec3D::set_z(const double &z)
    {
        vec->at(2) = z;
    }

    void Vec3D::set_xyz(const double &x, const double &y, const double &z)
    {
        vec->at(0) = x;
        vec->at(1) = y;
        vec->at(2) = z;
    }

    point Vec3D::get_point()
    {
        return *vec;
    }

    void Vec3D::normalize()
    {
        len = get_len();
        vec->at(0) /= len;
        vec->at(1) /= len;
        vec->at(2) /= len;
    }

    void Vec3D::print()
    {
        std::cout << "(";
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << vec->at(i);
            if (i != 2)
                std::cout << ",";
        }
        std::cout << ")\n";
    }
} // namespace cube
