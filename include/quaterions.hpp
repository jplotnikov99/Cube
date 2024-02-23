#pragma once
#include "3Dvector.hpp"
#include <cmath>

namespace cube
{
    class Quaterion
    {
    private:
        double theta;
        double i;
        double j;
        double k;

    public:
        Quaterion();
        Quaterion(const double &angle, const double &x, const double &y, const double &z);
        Quaterion(const double &angle, Vec3D &v);

        double get_theta();
        double get_i();
        double get_j();
        double get_k();
        double get_norm();

        void set_theta(const double &x);
        void set_i(const double &x);
        void set_j(const double &x);
        void set_k(const double &x);

        void set_q(const double &angle, const double &x, const double &y, const double &z);
        void set_q(const double &angle, Vec3D &v);

        void normalize();
        void conjugate();
        void invert();

        void print();

        ~Quaterion(){};
    };

} // namespace cube
