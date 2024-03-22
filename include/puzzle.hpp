#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "spot.hpp"
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

    

    typedef std::vector<Spot> line;
    typedef std::vector<line> area;
    typedef std::vector<area> volume;

    class Puzzle
    {
    private:
        volume cube;
        std::vector<std::unique_ptr<Piece>> pieces;
        size_t cur_piece = 0;

    public:
        Puzzle();
        void update_neighbours(const Spot &a);
        bool is_free(std::unique_ptr<Piece> &p);
        bool next_step(std::unique_ptr<Piece> &p);
        bool check_x_fit(std::unique_ptr<Piece> &p);
        bool check_y_fit(std::unique_ptr<Piece> &p);
        bool check_z_fit(std::unique_ptr<Piece> &p);
        bool does_piece_fit(std::unique_ptr<Piece> &p);
        size_t get_N_neighbours(const size_t i, const size_t j, const size_t k);
        void put_piece(std::unique_ptr<Piece> &p);
        void remove_piece(std::unique_ptr<Piece> &p);
        void reset_piece(std::unique_ptr<Piece> &p);
        void forward_track();

        void print();
        ~Puzzle(){};
    };

} // namespace cube
