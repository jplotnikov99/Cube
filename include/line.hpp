#pragma once
#include <vector>
#include "3Dvector.hpp"
#include "operators.hpp"

namespace cube
{
    class Line
    {
    private:
        std::unique_ptr<Vec3D> start_point;
        std::unique_ptr<Vec3D> end_point;
        std::unique_ptr<Vec3D> line_vec;
        double lenght;

    public:
        Line();
        Line(const double &v1_x, const double &v1_y, const double &v1_z, const double &v2_x, const double &v2_y, const double &v2_z);
        Line(std::unique_ptr<Vec3D> &start, std::unique_ptr<Vec3D> &end);

        void connect();

        void update_start(const double &v_x, const double &v_y, const double &v_z);
        void update_start(std::unique_ptr<Vec3D> &start);
        void update_end(const double &v_x, const double &v_y, const double &v_z);
        void update_end(std::unique_ptr<Vec3D> &end);

        std::unique_ptr<Vec3D> get_start();
        std::unique_ptr<Vec3D> get_end();
        std::unique_ptr<Vec3D> get_line();
        double get_length();
        double get_xy_slope();
        double get_xz_slope();
        double get_yz_slope();

        void rotate(const double &angle, Vec3D &rot_axis);

        void print();

        ~Line(){
            // std::cout << "Line destroyed\n";
        };
    };

} // namespace cube
