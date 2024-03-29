#pragma once
#include <iostream>
#include <vector>

namespace cube
{

    enum Direction
    {
        left,
        right,
        up,
        down,
        front,
        back
    };

    class Piece
    {
    private:
        size_t ID;
        size_t x_pos = 0;
        size_t y_pos = 0;
        size_t z_pos = 0;
        size_t len_tail = 2;
        size_t len_nose = 1;
        Direction tail;
        Direction nose;
        static const size_t N_configurations = 24;
        size_t cur_configuration = 0;

    public:
        Piece(const size_t piece_ID);
        size_t get_ID();
        size_t get_x_pos();
        size_t get_y_pos();
        size_t get_z_pos();
        void set_x_pos(const size_t x);
        void set_y_pos(const size_t y);
        void set_z_pos(const size_t z);
        void reset_pos();
        Direction get_tail_dir();
        Direction get_nose_dir();
        size_t get_N_configurations();
        void configure(const size_t N);
        void reset_configuration();
        bool next_configuration();
        ~Piece(){};
    };
} // namespace cube