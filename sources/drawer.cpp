#include "drawer.hpp"

namespace cube
{
    Drawer::Drawer()
    {
        frame = std::make_unique<Frame>();
        frame_mid_h = std::round((double)frame->get_height() / 2);
        frame_mid_w = std::round((double)frame->get_width() / 2);
    }

    void Drawer::draw_line(std::unique_ptr<Line> &l)
    {
        std::unique_ptr<Vec3D> start = l->get_start();
        std::unique_ptr<Vec3D> end = l->get_end();
        std::unique_ptr<Vec3D> line = l->get_line();

        double slope = fabs(l->get_yz_slope());
        std::uint16_t row_pixel = -std::round(start->get_z()) + frame_mid_h;
        std::uint16_t col_pixel = std::round(start->get_y()) + frame_mid_w;

        frame->activate_pixel(row_pixel, col_pixel);

        double step = slope > 1. ? 1 / fabs(line->get_z()) : 1 / fabs(line->get_y());
        start->set_x(end->get_x());

        int i = 0;

        while (!is_same(*start, *end))
        {
            start->set_y(start->get_y() + step * line->get_y());
            start->set_z(start->get_z() + step * line->get_z());

            row_pixel = -std::round(start->get_z()) + frame_mid_h;
            col_pixel = std::round(start->get_y()) + frame_mid_w;

            frame->activate_pixel(row_pixel, col_pixel);
        }
    }

    void Drawer::show()
    {
        frame->show();
    }
} // namespace cube
