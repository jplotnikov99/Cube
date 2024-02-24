#pragma once
#include <cassert>
#include "3Dvector.hpp"
#include "quaterions.hpp"

namespace cube
{
    double truncate(const double &x);

    void v_add(Vec3D &p1, Vec3D &p2, Vec3D &res);

    void v_sub(Vec3D &p1, Vec3D &p2, Vec3D &res);

    void v_div_s(Vec3D &p1, const double N);

    bool is_same(Vec3D &p1, Vec3D &p2);

    void q_add(Quaterion &q1, Quaterion &q2, Quaterion &res);

    void q_sub(Quaterion &q1, Quaterion &q2, Quaterion &res);

    void q_mult(const double &x, Quaterion &q);

    void q_mult(Quaterion &q1, Quaterion &q2, Quaterion &res);

    void v_rotate(const double &angle, Vec3D &rot_axis, Vec3D &v);

} // namespace cube
