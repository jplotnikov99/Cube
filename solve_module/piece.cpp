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

    volume Piece::get_shape()
    {
        return shape;
    }

    void Piece::configure(const size_t N)
    {
        shape.clear();
        switch (N)
        {
        case 1:
            cur_configuration = 1;
            shape.push_back({});
            shape.at(0).push_back({ID, ID, ID, ID}); // ID ID ID ID
            shape.at(0).push_back({0, ID, 0, 0});    //    ID
            tail = right;
            nose = down;
            break;
        case 2:
            cur_configuration = 2;
            shape.push_back({});
            shape.at(0).push_back({ID, ID, ID, ID}); // ID ID ID ID
            shape.at(0).push_back({0, 0, ID, 0});    //       ID
            tail = left;
            nose = down;
            break;
        case 3:
            cur_configuration = 3;
            shape.push_back({});
            shape.at(0).push_back({0, ID, 0, 0});    //    ID
            shape.at(0).push_back({ID, ID, ID, ID}); // ID ID ID ID
            tail = right;
            nose = up;
            break;
        case 4:
            cur_configuration = 4;
            shape.push_back({});
            shape.at(0).push_back({0, 0, ID, 0});    //       ID
            shape.at(0).push_back({ID, ID, ID, ID}); // ID ID ID ID
            tail = left;
            nose = up;
            break;
        case 5:
            cur_configuration = 5;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID, ID, ID, ID}); // ID ID ID ID
            shape.at(1).push_back({0, ID, 0, 0});
            tail = right;
            nose = front;
            break;
        case 6:
            cur_configuration = 6;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID, ID, ID, ID}); // ID ID ID ID
            shape.at(1).push_back({0, 0, ID, 0});
            tail = left;
            nose = front;
            break;
        case 7:
            cur_configuration = 7;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0, ID, 0, 0});
            shape.at(1).push_back({ID, ID, ID, ID}); // ID ID ID ID
            tail = right;
            nose = back;
            break;
        case 8:
            cur_configuration = 8;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0, 0, ID, 0});
            shape.at(1).push_back({ID, ID, ID, ID}); // ID ID ID ID
            tail = left;
            nose = back;
            break;
        case 9:
            cur_configuration = 9;
            shape.push_back({});
            shape.at(0).push_back({ID, 0});  // ID
            shape.at(0).push_back({ID, ID}); // ID ID
            shape.at(0).push_back({ID, 0});  // ID
            shape.at(0).push_back({ID, 0});  // ID
            tail = down;
            nose = right;
            break;
        case 10:
            cur_configuration = 10;
            shape.push_back({});
            shape.at(0).push_back({ID, 0});  // ID
            shape.at(0).push_back({ID, 0});  // ID
            shape.at(0).push_back({ID, ID}); // ID ID
            shape.at(0).push_back({ID, 0});  // ID
            tail = up;
            nose = right;
            break;
        case 11:
            cur_configuration = 11;
            shape.push_back({});
            shape.at(0).push_back({0, ID});  //    ID
            shape.at(0).push_back({ID, ID}); // ID ID
            shape.at(0).push_back({0, ID});  //    ID
            shape.at(0).push_back({0, ID});  //    ID
            tail = down;
            nose = left;
            break;
        case 12:
            cur_configuration = 12;
            shape.push_back({});
            shape.at(0).push_back({0, ID});  //    ID
            shape.at(0).push_back({0, ID});  //    ID
            shape.at(0).push_back({ID, ID}); // ID ID
            shape.at(0).push_back({0, ID});  //    ID
            tail = up;
            nose = left;
            break;
        case 13:
            cur_configuration = 13;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID}); // ID
            shape.at(0).push_back({ID}); // ID
            shape.at(0).push_back({ID}); // ID
            shape.at(0).push_back({ID}); // ID
            shape.at(1).push_back({0});
            shape.at(1).push_back({ID});
            shape.at(1).push_back({0});
            shape.at(1).push_back({0});
            tail = down;
            nose = front;
            break;
        case 14:
            cur_configuration = 14;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID}); // ID
            shape.at(0).push_back({ID}); // ID
            shape.at(0).push_back({ID}); // ID
            shape.at(0).push_back({ID}); // ID
            shape.at(1).push_back({0});
            shape.at(1).push_back({0});
            shape.at(1).push_back({ID});
            shape.at(1).push_back({0});
            tail = up;
            nose = front;
            break;
        case 15:
            cur_configuration = 15;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0});
            shape.at(0).push_back({ID});
            shape.at(0).push_back({0});
            shape.at(0).push_back({0});
            shape.at(1).push_back({ID}); // ID
            shape.at(1).push_back({ID}); // ID
            shape.at(1).push_back({ID}); // ID
            shape.at(1).push_back({ID}); // ID
            tail = down;
            nose = back;
            break;
        case 16:
            cur_configuration = 16;
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0});
            shape.at(0).push_back({0});
            shape.at(0).push_back({ID});
            shape.at(0).push_back({0});
            shape.at(1).push_back({ID}); // ID
            shape.at(1).push_back({ID}); // ID
            shape.at(1).push_back({ID}); // ID
            shape.at(1).push_back({ID}); // ID
            tail = up;
            nose = back;
            break;
        case 17:
            cur_configuration = 17;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID, 0});
            shape.at(1).push_back({ID, ID});
            shape.at(2).push_back({ID, 0});
            shape.at(3).push_back({ID, 0});
            tail = front;
            nose = right;
            break;
        case 18:
            cur_configuration = 18;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID, 0});
            shape.at(1).push_back({ID, 0});
            shape.at(2).push_back({ID, ID});
            shape.at(3).push_back({ID, 0});
            tail = back;
            nose = right;
            break;
        case 19:
            cur_configuration = 19;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0, ID});
            shape.at(1).push_back({ID, ID});
            shape.at(2).push_back({0, ID});
            shape.at(3).push_back({0, ID});
            tail = front;
            nose = left;
            break;
        case 20:
            cur_configuration = 20;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0, ID});
            shape.at(1).push_back({0, ID});
            shape.at(2).push_back({ID, ID});
            shape.at(3).push_back({0, ID});
            tail = back;
            nose = left;
            break;
        case 21:
            cur_configuration = 21;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID});
            shape.at(0).push_back({0});
            shape.at(1).push_back({ID});
            shape.at(1).push_back({ID});
            shape.at(2).push_back({ID});
            shape.at(2).push_back({0});
            shape.at(3).push_back({ID});
            shape.at(3).push_back({0});
            tail = front;
            nose = down;
            break;
        case 22:
            cur_configuration = 22;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({ID});
            shape.at(0).push_back({0});
            shape.at(1).push_back({ID});
            shape.at(1).push_back({0});
            shape.at(2).push_back({ID});
            shape.at(2).push_back({ID});
            shape.at(3).push_back({ID});
            shape.at(3).push_back({0});
            tail = back;
            nose = down;
            break;
        case 23:
            cur_configuration = 23;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0});
            shape.at(0).push_back({ID});
            shape.at(1).push_back({ID});
            shape.at(1).push_back({ID});
            shape.at(2).push_back({0});
            shape.at(2).push_back({ID});
            shape.at(3).push_back({0});
            shape.at(3).push_back({ID});
            tail = front;
            nose = up;
            break;
        case 24:
            cur_configuration = 24;
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.push_back({});
            shape.at(0).push_back({0});
            shape.at(0).push_back({ID});
            shape.at(1).push_back({0});
            shape.at(1).push_back({ID});
            shape.at(2).push_back({ID});
            shape.at(2).push_back({ID});
            shape.at(3).push_back({0});
            shape.at(3).push_back({ID});
            tail = back;
            nose = up;
            break;

        default:
            std::cout << "Shape configuration does not exists\n";
            break;
        }
    }

    bool Piece::next_configuration()
    {
        if(cur_configuration == 24)
        {
            return false;
        }
        configure(cur_configuration++);
        return true;
    }

    void Piece::print()
    {
        for (auto it : shape)
        {
            for (auto jt : it)
            {
                for (auto kt : jt)
                {
                    std::cout << kt << " ";
                }
                std::cout << "\n";
            }
            std::cout << "----------------------------------------\n";
        }
    }
} // namespace cube