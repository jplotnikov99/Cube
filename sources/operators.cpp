#include "operators.hpp"

namespace cube
{

    void v_add(Vec3D &p1, Vec3D &p2, Vec3D &res)
    {
        res.set_x(p1.get_x() + p2.get_x());
        res.set_y(p1.get_y() + p2.get_y());
        res.set_z(p1.get_z() + p2.get_z());
    }

    void v_sub(Vec3D &p1, Vec3D &p2, Vec3D &res)
    {
        res.set_x(p1.get_x() - p2.get_x());
        res.set_y(p1.get_y() - p2.get_y());
        res.set_z(p1.get_z() - p2.get_z());
    }

    void v_div_s(Vec3D &p1, const double N)
    {
        p1.set_x(p1.get_x() / N);
        p1.set_y(p1.get_y() / N);
        p1.set_z(p1.get_z() / N);
    }

    bool is_same(Vec3D &p1, Vec3D &p2)
    {
        if(fabs(p1.get_x() - p2.get_x()) > 1e-12) return false;
        if(fabs(p1.get_y() - p2.get_y()) > 1e-12) return false;
        if(fabs(p1.get_z() - p2.get_z()) > 1e-12) return false;
        return true;
    }
} // namespace cube
