#include "line.hpp"

namespace cube
{

    Line::Line()
    {
        start_point = std::make_unique<Vec3D>(0, 0, 0);
        end_point = std::make_unique<Vec3D>(1, 1, 1);
        line_vec = std::make_unique<Vec3D>();
        connect();
    }

    Line::Line(const double &v1_x, const double &v1_y, const double &v1_z, const double &v2_x, const double &v2_y, const double &v2_z)
    {
        start_point = std::make_unique<Vec3D>(v1_x, v1_y, v1_z);
        end_point = std::make_unique<Vec3D>(v2_x, v2_y, v2_z);
        line_vec = std::make_unique<Vec3D>();
        connect();
    }

    Line::Line(std::unique_ptr<Vec3D> &start, std::unique_ptr<Vec3D> &end)
    {
        start_point = std::move(start);
        end_point = std::move(end);
        line_vec = std::make_unique<Vec3D>();
        connect();
    }

    void Line::connect()
    {
        v_sub(*end_point, *start_point, *line_vec);
        lenght = line_vec->get_len();
    }

    void Line::update_start(const double &v_x, const double &v_y, const double &v_z)
    {
        start_point = std::make_unique<Vec3D>(v_x, v_y, v_z);
        connect();
    }

    void Line::update_start(std::unique_ptr<Vec3D> &start)
    {
        start_point = std::move(start);
        connect();
    }

    void Line::update_end(const double &v_x, const double &v_y, const double &v_z)
    {
        end_point = std::make_unique<Vec3D>(v_x, v_y, v_z);
        connect();
    }

    void Line::update_end(std::unique_ptr<Vec3D> &end)
    {
        end_point = std::move(end);
        connect();
    }

    std::unique_ptr<Vec3D> Line::get_start()
    {
        std::unique_ptr<Vec3D> res = std::make_unique<Vec3D>(start_point->get_x(), start_point->get_y(), start_point->get_z());
        return res;
    }
    std::unique_ptr<Vec3D> Line::get_end()
    {
        std::unique_ptr<Vec3D> res = std::make_unique<Vec3D>(end_point->get_x(), end_point->get_y(), end_point->get_z());
        return res;
    }
    std::unique_ptr<Vec3D> Line::get_line()
    {
        std::unique_ptr<Vec3D> res = std::make_unique<Vec3D>(line_vec->get_x(), line_vec->get_y(), line_vec->get_z());
        return res;
    }

    double Line::get_length()
    {
        return lenght;
    }

    double Line::get_xy_slope()
    {
        return line_vec->get_y()/line_vec->get_x();
    }
    double Line::get_xz_slope()
    {
        return line_vec->get_z()/line_vec->get_x();
    }
    double Line::get_yz_slope()
    {
        return line_vec->get_z()/line_vec->get_y();
    }

    void Line::print()
    {
        std::cout << "Start point:\n";
        start_point->print();
        std::cout << "End point:\n";
        end_point->print();
        std::cout << "Vector from Start to End point:\n";
        line_vec->print();
        std::cout << "Lenght:\n";
        std::cout << lenght << "\n";
    }
} // namespace cube
