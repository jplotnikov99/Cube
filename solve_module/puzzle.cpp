#include "puzzle.hpp"

namespace cube
{
    Puzzle::Puzzle()
    {
        for (size_t i = 0; i < 8; i++)
        {
            cube.push_back({});
            for (size_t j = 0; j < 8; j++)
            {
                cube.at(i).push_back({0, 0, 0, 0, 0, 0, 0, 0});
            }
        }
        for (size_t i = 1; i <= 25; i++)
        {
            pieces.push_back(std::make_unique<Piece>(i));
        }
    }

    bool Puzzle::check_x_fit(std::unique_ptr<Piece> &p)
    {
        size_t cur_x = p->get_x_pos();
        DIRECTIONCASES(back, front, cur_x)
    }

    bool Puzzle::check_y_fit(std::unique_ptr<Piece> &p)
    {
        size_t cur_y = p->get_y_pos();
        DIRECTIONCASES(left, right, cur_y)
    }

    bool Puzzle::check_z_fit(std::unique_ptr<Piece> &p)
    {
        size_t cur_z = p->get_z_pos();
        DIRECTIONCASES(down, up, cur_z)
    }

    bool Puzzle::does_piece_fit(std::unique_ptr<Piece> &p, const Side side)
    {
        switch (side)
        {
        case Side::left:
            check_y_fit(p);
            check_z_fit(p);
            break;
        case Side::right:
            check_x_fit(p);
            check_z_fit(p);
            break;
        case Side::top:
            check_x_fit(p);
            check_y_fit(p);
            break;

        default:
            std::cout << "Side does not exist\n";
            exit(1);
            break;
        }
    }

    void Puzzle::put_next_piece(std::unique_ptr<Piece> &p, const Side side)
    {
        switch (side)
        {
        case left:

            break;
        case right:
            break;
        case top:
            break;

        default:
            break;
        }
    }

    void Puzzle::print()
    {
        for (auto it : cube)
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
