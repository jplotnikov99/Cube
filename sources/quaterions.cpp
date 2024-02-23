#include "quaterions.hpp"

namespace cube
{

    Quaterion::Quaterion()
    {
        theta = 0;
        i = 0;
        j = 0;
        k = 0;
    }

    Quaterion::Quaterion(const double &angle, const double &x, const double &y, const double &z)
    {
        theta = angle;
        i = x;
        j = y;
        k = z;
    }
    Quaterion::Quaterion(const double &angle, Vec3D &v)
    {
        theta = angle;
        i = v.get_x();
        j = v.get_y();
        k = v.get_z();
    }

    double Quaterion::get_theta()
    {
        return theta;
    }

    double Quaterion::get_i()
    {
        return i;
    }

    double Quaterion::get_j()
    {
        return j;
    }

    double Quaterion::get_k()
    {
        return k;
    }

    double Quaterion::get_norm()
    {
        return sqrt(theta * theta + i * i + j * j + k * k);
    }

    void Quaterion::set_theta(const double &x)
    {
        theta = x;
    }

    void Quaterion::set_i(const double &x)
    {
        i = x;
    }

    void Quaterion::set_j(const double &x)
    {
        j = x;
    }

    void Quaterion::set_k(const double &x)
    {
        k = x;
    }

    void Quaterion::set_q(const double &angle, const double &x, const double &y, const double &z)
    {
        theta = angle;
        i = x;
        j = y;
        k = z;
    }

    void Quaterion::set_q(const double &angle, Vec3D &v)
    {
        theta = angle;
        i = v.get_x();
        j = v.get_y();
        k = v.get_z();
    }

    void Quaterion::normalize()
    {
        double norm = get_norm();
        i /= norm;
        j /= norm;
        k /= norm;
    }

    void Quaterion::conjugate()
    {
        i *= -1;
        j *= -1;
        k *= -1;
    }

    void Quaterion::invert()
    {
        double normsq = pow(get_norm(), 2);
        conjugate();
        theta /= normsq;
        i /= normsq;
        j /= normsq;
        k /= normsq;
    }

    void Quaterion::print()
    {
        std::cout << theta;
        if (i > 0)
        {
            std::cout << "+" << i;
        }
        else
        {
            std::cout << i;
        }
        if (j > 0)
        {
            std::cout << "+" << j;
        }
        else
        {
            std::cout << j;
        }
        if (k > 0)
        {
            std::cout << "+" << k;
        }
        else
        {
            std::cout << k;
        }
        std::cout << "\n";
    }
} // namespace cube
