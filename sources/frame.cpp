#include "frame.hpp"

namespace cube
{
    Frame::Frame()
    {
        F = std::make_unique<frame>();
        for (std::uint16_t i = 0; i < HEIGHT; i++)
        {
            F->push_back({});
            for (std::uint16_t j = 0; j < WIDTH; j++)
            {
                F->at(i).push_back(0);
            }
        }
    }
    Frame::Frame(std::unique_ptr<frame> &pic)
    {
        assert((std::uint16_t)pic->size() == HEIGHT);
        for (auto it : *pic)
        {
            assert(it.size() == WIDTH);
        }

        F = std::move(pic);
    }

    std::uint16_t Frame::get_height()
    {
        return HEIGHT;
    }

    std::uint16_t Frame::get_width()
    {
        return WIDTH;
    }

    void Frame::activate_pixel(const std::uint16_t &row, const std::uint16_t &col)
    {
        assert(row <= HEIGHT);
        assert(col <= WIDTH);
        F->at(row - 1).at(col - 1) = true;
    }

    void Frame::activate_pixel_row(const std::uint16_t &row)
    {
        assert(row <= HEIGHT);
        for (auto it : F->at(row - 1))
        {
            it = true;
        }
    }

    void Frame::activate_pixel_col(const std::uint16_t &col)
    {
        assert(col <= WIDTH);
        for (auto &it : *F)
        {
            it.at(col - 1) = true;
        }
    }

    void Frame::switch_pixel(const std::uint16_t &row, const std::uint16_t &col)
    {
        assert(row <= HEIGHT);
        assert(col <= WIDTH);
        F->at(row - 1).at(col - 1) = !F->at(row - 1).at(col - 1);
    }

    void Frame::switch_pixel_row(const std::uint16_t &row)
    {
        assert(row <= HEIGHT);
        for (auto it : F->at(row - 1))
        {
            it = !it;
        }
    }

    void Frame::switch_pixel_col(const std::uint16_t &col)
    {
        assert(col <= WIDTH);
        for (auto &it : *F)
        {
            it.at(col - 1) = !it.at(col - 1);
        }
    }

    void Frame::update(std::unique_ptr<frame> &pic)
    {
        assert((std::uint16_t)pic->size() == HEIGHT);
        for (auto it : *pic)
        {
            assert(it.size() == WIDTH);
        }
        F = std::move(pic);
    }

    void Frame::clear()
    {
        for (auto &it : *F)
        {
            for (auto jt : it)
            {
                jt = false;
            }
        }
    }

    void Frame::show()
    {
        system("clear");
        for (auto it : *F)
        {
            for (auto jt : it)
            {
                if (jt)
                {
                    std::cout << full;
                }
                else
                {
                    std::cout << empty;
                }
            }
            std::cout << "\n";
        }
    }

} // namespace cube
