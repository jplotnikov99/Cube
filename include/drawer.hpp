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

        void draw_line(std::unique_ptr<Line> &l);

        void show();

        ~Drawer(){};
    };

} // namespace cube
