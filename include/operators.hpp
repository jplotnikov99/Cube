#pragma once
#include "3Dvector.hpp"
#include <cassert>

namespace cube
{
    void v_add(Vec3D &p1, Vec3D &p2, Vec3D &res);

    void v_sub(Vec3D &p1, Vec3D &p2, Vec3D &res);

    void v_div_s(Vec3D &p1, const double N);

    bool is_same(Vec3D &p1, Vec3D &p2);

} // namespace cube
