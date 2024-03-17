#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "piece.hpp"

namespace cube
{
#define DIRECTIONCASES(dir1, dir2, axis) \
    if (axis != 2)                       \
    {                                    \
        switch (p->get_tail_dir())       \
        {                                \
        case Direction::dir1:            \
            if (axis == 3)               \
            {                            \
                return true;             \
            }                            \
            break;                       \
        case Direction::dir2:            \
            if (axis == 1)               \
            {                            \
                return true;             \
            }                            \
            break;                       \
        default:                         \
            switch (p->get_nose_dir())   \
            {                            \
            case Direction::dir1:        \
                if (axis > 0)            \
                {                        \
                    return true;         \
                }                        \
                break;                   \
            case Direction::dir2:        \
                if (axis < 4)            \
                {                        \
                    return true;         \
                }                        \
                break;                   \
            default:                     \
                return true;             \
                break;                   \
            }                            \
            break;                       \
        }                                \
        return false;                    \
    }                                    \
    return true;
    class Puzzle
    {
    private:
        volume cube;
        std::vector<std::unique_ptr<Piece>> pieces;
        enum Side
        {
            left,
            right,
            top
        };

    public:
        Puzzle();
        bool check_x_fit(std::unique_ptr<Piece> &p);
        bool check_y_fit(std::unique_ptr<Piece> &p);
        bool check_z_fit(std::unique_ptr<Piece> &p);
        bool does_piece_fit(std::unique_ptr<Piece> &p, const Side side);
        void put_next_piece(std::unique_ptr<Piece> &p, const Side side);

        void print();
        ~Puzzle(){};
    };

} // namespace cube
