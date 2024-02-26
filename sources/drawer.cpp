#include "drawer.hpp"

namespace cube
{
    Drawer::Drawer()
    {
        frame = std::make_unique<Frame>();
        frame_h = frame->get_height();
        frame_w = frame->get_width();
        frame_mid_h = std::round((double)frame_h / 2);
        frame_mid_w = std::round((double)frame_w / 2);
    }

    void Drawer::vec_to_pixel(std::unique_ptr<Vec3D> &v)
    {
        int row_pixel = -std::round(v->get_z()) + (int)frame_mid_h;
        int col_pixel = std::round(v->get_y()) + (int)frame_mid_w;
        if (row_pixel > frame_h)
            row_pixel = frame_h;
        if (col_pixel > frame_w)
            col_pixel = frame_w;
        if (row_pixel < 1)
            row_pixel = 1;
        if (col_pixel < 1)
            col_pixel = 1;
        frame->activate_pixel((std::uint16_t)row_pixel, (std::uint16_t)col_pixel);
    }

    void Drawer::draw_line(std::unique_ptr<Line> &l)
    {
        std::unique_ptr<Vec3D> start = l->get_start();
        std::unique_ptr<Vec3D> line = l->get_line();
        std::unique_ptr<Vec3D> unit = std::make_unique<Vec3D>();
        double steps = line->get_len();
        line->normalize();

        vec_to_pixel(start);

        for (size_t i = 0; i < (int)steps; i++)
        {
            v_add(*start, *line, *start);
            vec_to_pixel(start);
        }

        v_mult_s(*line, truncate(steps));
        v_add(*start, *line, *start);
        vec_to_pixel(start);
    }

    void Drawer::draw_shape(std::unique_ptr<Shapes> &s)
    {
        size_t N = s->get_N_lines();
        for(size_t i = 0; i < N; i++)
        {
            draw_line(s->lines.at(i));
        }
    }

    void Drawer::clear_frame()
    {
        frame->clear();
    }

    void Drawer::show()
    {
        frame->show();
    }
} // namespace cube
