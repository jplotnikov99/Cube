#pragma once
#include <memory>
#include "frame.hpp"
#include "line.hpp"
#include "shapes.hpp"

namespace cube
{
    class Drawer
    {
    private:
        std::unique_ptr<Frame> frame;
        std::uint16_t frame_h;
        std::uint16_t frame_w;
        std::uint16_t frame_mid_h;
        std::uint16_t frame_mid_w;

    public:
        Drawer();

        void vec_to_pixel(std::unique_ptr<Vec3D> &v);

        void draw_line(std::unique_ptr<Line> &l);

        void draw_shape(std::unique_ptr<Shapes> &s);

        void clear_frame();

        void show();

        ~Drawer(){};
    };

} // namespace cube
