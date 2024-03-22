#include "piece.hpp"

namespace cube
{
    Piece::Piece(const size_t piece_ID)
    {
        ID = piece_ID;
    }

    size_t Piece::get_ID()
    {
        return ID;
    }

    size_t Piece::get_N_configurations()
    {
        return N_configurations;
    }

    size_t Piece::get_x_pos()
    {
        return x_pos;
    }

    size_t Piece::get_y_pos()
    {
        return y_pos;
    }

    size_t Piece::get_z_pos()
    {
        return z_pos;
    }

    void Piece::set_x_pos(const size_t x)
    {
        x_pos = x;
    }

    void Piece::set_y_pos(const size_t y)
    {
        y_pos = y;
    }

    void Piece::set_z_pos(const size_t z)
    {
        z_pos = z;
    }

    void Piece::reset_pos()
    {
        x_pos = 0;
        y_pos = 0;
        z_pos = 0;
    }

    Direction Piece::get_tail_dir()
    {
        return tail;
    }

    Direction Piece::get_nose_dir()
    {
        return nose;
    }

    void Piece::configure(const size_t N)
    {
        switch (N)
        {
        case 1:
            cur_configuration = 1;
            tail = right;
            nose = down;
            break;
        case 2:
            cur_configuration = 2;
            tail = left;
            nose = down;
            break;
        case 3:
            cur_configuration = 3;
            tail = right;
            nose = up;
            break;
        case 4:
            cur_configuration = 4;
            tail = left;
            nose = up;
            break;
        case 5:
            cur_configuration = 5;
            tail = right;
            nose = front;
            break;
        case 6:
            cur_configuration = 6;
            tail = left;
            nose = front;
            break;
        case 7:
            cur_configuration = 7;
            tail = right;
            nose = back;
            break;
        case 8:
            cur_configuration = 8;
            tail = left;
            nose = back;
            break;
        case 9:
            cur_configuration = 9;
            tail = down;
            nose = right;
            break;
        case 10:
            cur_configuration = 10;
            tail = up;
            nose = right;
            break;
        case 11:
            cur_configuration = 11;
            tail = down;
            nose = left;
            break;
        case 12:
            cur_configuration = 12;
            tail = up;
            nose = left;
            break;
        case 13:
            cur_configuration = 13;
            tail = down;
            nose = front;
            break;
        case 14:
            cur_configuration = 14;
            tail = up;
            nose = front;
            break;
        case 15:
            cur_configuration = 15;
            tail = down;
            nose = back;
            break;
        case 16:
            cur_configuration = 16;
            tail = up;
            nose = back;
            break;
        case 17:
            cur_configuration = 17;
            tail = front;
            nose = right;
            break;
        case 18:
            cur_configuration = 18;
            tail = back;
            nose = right;
            break;
        case 19:
            cur_configuration = 19;
            tail = front;
            nose = left;
            break;
        case 20:
            cur_configuration = 20;
            tail = back;
            nose = left;
            break;
        case 21:
            cur_configuration = 21;
            tail = front;
            nose = down;
            break;
        case 22:
            cur_configuration = 22;
            tail = back;
            nose = down;
            break;
        case 23:
            cur_configuration = 23;
            tail = front;
            nose = up;
            break;
        case 24:
            cur_configuration = 24;
            tail = back;
            nose = up;
            break;

        default:
            std::cout << "Shape configuration does not exists\n";
            break;
        }
    }

    void Piece::reset_configuration()
    {
        cur_configuration = 0;
    }

    bool Piece::next_configuration()
    {
        if(cur_configuration == 24)
        {
            return false;
        }
        cur_configuration++;
        configure(cur_configuration);
        return true;
    }

    
} // namespace cube