#pragma once
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <memory>
#include <string>
#include <cassert>
#include <vector>

namespace cube
{
    typedef bool pixel;
    typedef std::vector<pixel> pixel_row;
    typedef std::vector<pixel_row> frame;

    class Frame
    {
    private:
        const std::uint16_t HEIGHT = 101;
        const std::uint16_t WIDTH = 151;
        const std::string empty = "* ";
        const std::string full = "0 ";
        std::unique_ptr<frame> F;

    public:
        Frame();
        Frame(std::unique_ptr<frame> &pic);

        std::uint16_t get_height();
        std::uint16_t get_width();

        void activate_pixel(const std::uint16_t &row, const std::uint16_t &col);
        void activate_pixel_row(const std::uint16_t &row);
        void activate_pixel_col(const std::uint16_t &col);

        void switch_pixel(const std::uint16_t &row, const std::uint16_t &col);
        void switch_pixel_row(const std::uint16_t &row);
        void switch_pixel_col(const std::uint16_t &col);

        void update(std::unique_ptr<frame> &pic);
        void clear();
        void show();

        ~Frame(){};
    };
} // namespace cube
