#include "operators.hpp"

namespace cube
{

    double truncate(const double &x)
    {
        if (fabs(x) < 1e-15)
        {
            return 0.;
        }
        return x;
    }

    bool is_same(Vec3D &p1, Vec3D &p2)
    {
        if (fabs(p1.get_x() - p2.get_x()) > 1e-12)
            return false;
        if (fabs(p1.get_y() - p2.get_y()) > 1e-12)
            return false;
        if (fabs(p1.get_z() - p2.get_z()) > 1e-12)
            return false;
        return true;
    }

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

    void q_add(Quaterion &q1, Quaterion &q2, Quaterion &res)
    {
        res.set_q(q1.get_theta() + q2.get_theta(), q1.get_i() + q2.get_i(), q1.get_j() + q2.get_j(), q1.get_k() + q2.get_k());
    }

    void q_sub(Quaterion &q1, Quaterion &q2, Quaterion &res)
    {
        res.set_q(q1.get_theta() - q2.get_theta(), q1.get_i() - q2.get_i(), q1.get_j() - q2.get_j(), q1.get_k() - q2.get_k());
    }

    void q_mult(const double &x, Quaterion &q)
    {
        q.set_theta(q.get_theta() * x);
        q.set_i(q.get_i() * x);
        q.set_j(q.get_j() * x);
        q.set_k(q.get_k() * x);
    }

    void q_mult(Quaterion &q1, Quaterion &q2, Quaterion &res)
    {
        double a1 = q1.get_theta();
        double b1 = q1.get_i();
        double c1 = q1.get_j();
        double d1 = q1.get_k();
        double a2 = q2.get_theta();
        double b2 = q2.get_i();
        double c2 = q2.get_j();
        double d2 = q2.get_k();

        res.set_theta(a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2);
        res.set_i(a1 * b2 + b1 * a2 + c1 * d2 - d1 * c2);
        res.set_j(a1 * c2 - b1 * d2 + c1 * a2 + d1 * b2);
        res.set_k(a1 * d2 + b1 * c2 - c1 * b2 + d1 * a2);
    }

    void v_rotate(const double &angle, Vec3D &rot_axis, Vec3D &v)
    {
        Quaterion u(0, rot_axis);
        Quaterion p(0, v);
        Quaterion q(0, rot_axis);

        q.normalize();
        q_mult(sin(angle / 2), q);
        q.set_theta(cos(angle / 2));

        q_mult(q, p, p);
        q.invert();
        q_mult(p, q, p);

        v.set_x(p.get_i());
        v.set_y(p.get_j());
        v.set_z(p.get_k());
    }

} // namespace cube
