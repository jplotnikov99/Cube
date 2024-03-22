#include "puzzle.hpp"

namespace cube
{
    Puzzle::Puzzle()
    {
        Spot s{0, 0, 0};
        for (size_t i = 0; i < 5; i++)
        {
            cube.push_back({});
            for (size_t j = 0; j < 5; j++)
            {
                cube.at(i).push_back({});
                for (size_t k = 0; k < 5; k++)
                {
                    s.criticalness = 0;
                    s.N_neighbours = 0;
                    s.neighbours.clear();
                    if (i == 0)
                    {
                        s.criticalness++;
                        s.N_neighbours++;
                        s.neighbours.push_back({1, j, k});
                    }
                    else if (i == 4)
                    {
                        s.criticalness++;
                        s.N_neighbours++;
                        s.neighbours.push_back({3, j, k});
                    }
                    else
                    {
                        s.N_neighbours += 2;
                        s.neighbours.push_back({i - 1, j, k});
                        s.neighbours.push_back({i + 1, j, k});
                    }
                    if (j == 0)
                    {
                        s.criticalness++;
                        s.N_neighbours++;
                        s.neighbours.push_back({i, 0, k});
                    }
                    else if (j == 4)
                    {
                        s.criticalness++;
                        s.N_neighbours++;
                        s.neighbours.push_back({i, 3, k});
                    }
                    else
                    {
                        s.N_neighbours += 2;
                        s.neighbours.push_back({i, j - 1, k});
                        s.neighbours.push_back({i, j + 1, k});
                    }
                    if (k == 0)
                    {
                        s.criticalness++;
                        s.N_neighbours++;
                        s.neighbours.push_back({i, j, 1});
                    }
                    else if (k == 4)
                    {
                        s.criticalness++;
                        s.N_neighbours++;
                        s.neighbours.push_back({i, j, 3});
                    }
                    else
                    {
                        s.N_neighbours += 2;
                        s.neighbours.push_back({i, j, k - 1});
                        s.neighbours.push_back({i, j, k + 1});
                    }

                    cube.at(i).at(j).push_back(s);
                }
            }
        }
        for (size_t i = 1; i <= 25; i++)
        {
            pieces.push_back(std::make_unique<Piece>(i));
        }
    }

    void Puzzle::update_neighbours(const Spot &a)
    {
        if (a.val != 0)
        {
            for (auto it : a.neighbours)
            {
                cube.at(it.at(0)).at(it.at(1)).at(it.at(2)).criticalness++;
            }
        }
        else
        {
            for (auto it : a.neighbours)
            {
                cube.at(it.at(0)).at(it.at(1)).at(it.at(2)).criticalness--;
            }
        }
    }

    bool Puzzle::is_free(std::unique_ptr<Piece> &p)
    {
        if (cube.at(p->get_x_pos()).at(4 - p->get_z_pos()).at(p->get_y_pos()) != 0)
            return false;
        return true;
    }

    bool Puzzle::next_step(std::unique_ptr<Piece> &p)
    {
        size_t x = p->get_x_pos();
        if (x < 4)
        {
            p->set_x_pos(x + 1);
            return true;
        }
        else
        {
            size_t y = p->get_y_pos();
            if (y < 4)
            {
                p->set_x_pos(0);
                p->set_y_pos(y + 1);
                return true;
            }
            else
            {
                size_t z = p->get_z_pos();
                if (z < 4)
                {
                    p->set_x_pos(0);
                    p->set_y_pos(0);
                    p->set_z_pos(z + 1);
                    return true;
                }
                else
                {
                    return false;
                }
            }
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

    bool Puzzle::does_piece_fit(std::unique_ptr<Piece> &p)
    {
        size_t x = p->get_x_pos();
        size_t y = p->get_y_pos();
        size_t z = p->get_z_pos();

        if (cube.at(x).at(4 - z).at(y) != 0)
            return false;

        if (!check_x_fit(p))
            return false;
        if (!check_y_fit(p))
            return false;
        if (!check_z_fit(p))
            return false;

        switch (p->get_tail_dir())
        {
        case Direction::left:
            if ((cube.at(x).at(4 - z).at(y - 1) != 0) ||
                (cube.at(x).at(4 - z).at(y - 2) != 0) ||
                (cube.at(x).at(4 - z).at(y + 1) != 0))
                return false;
            break;
        case Direction::right:
            if ((cube.at(x).at(4 - z).at(y + 1) != 0) ||
                (cube.at(x).at(4 - z).at(y + 2) != 0) ||
                (cube.at(x).at(4 - z).at(y - 1) != 0))
                return false;
            break;
        case Direction::up:
            if ((cube.at(x).at(4 - (z + 1)).at(y)) != 0 ||
                (cube.at(x).at(4 - (z + 2)).at(y)) != 0 ||
                (cube.at(x).at(4 - (z - 1)).at(y)) != 0)
                return false;
            break;
        case Direction::down:
            if ((cube.at(x).at(4 - (z - 1)).at(y)) != 0 ||
                (cube.at(x).at(4 - (z - 2)).at(y)) != 0 ||
                (cube.at(x).at(4 - (z + 1)).at(y)) != 0)
                return false;
            break;
        case Direction::front:
            if ((cube.at(x + 1).at(4 - z).at(y)) != 0 ||
                (cube.at(x + 2).at(4 - z).at(y) != 0) ||
                (cube.at(x - 1).at(4 - z).at(y) != 0))
                return false;
            break;
        case Direction::back:
            if ((cube.at(x - 1).at(4 - z).at(y) != 0) ||
                (cube.at(x - 2).at(4 - z).at(y) != 0) ||
                (cube.at(x + 1).at(4 - z).at(y) != 0))
                return false;
            break;

        default:
            std::cout << "Direction in " << __func__ << " does not exist.\n";
            exit(1);
            break;
        }

        switch (p->get_nose_dir())
        {
        case Direction::left:
            if (cube.at(x).at(4 - z).at(y - 1) != 0)
                return false;
            break;
        case Direction::right:
            if (cube.at(x).at(4 - z).at(y + 1) != 0)
                return false;
            break;
        case Direction::up:
            if (cube.at(x).at(4 - (z + 1)).at(y) != 0)
                return false;
            break;
        case Direction::down:
            if (cube.at(x).at(4 - (z - 1)).at(y) != 0)
                return false;
            break;
        case Direction::front:
            if (cube.at(x + 1).at(4 - z).at(y) != 0)
                return false;
            break;
        case Direction::back:
            if (cube.at(x - 1).at(4 - z).at(y) != 0)
                return false;
            break;

        default:
            std::cout << "Direction in " << __func__ << " does not exist.\n";
            exit(1);
            break;
        }
        return true;
    }

    void Puzzle::put_piece(std::unique_ptr<Piece> &p)
    {
        size_t x = p->get_x_pos();
        size_t y = p->get_y_pos();
        size_t z = p->get_z_pos();
        size_t ID = p->get_ID();

        cube.at(x).at(4 - z).at(y).val = ID;

        switch (p->get_tail_dir())
        {
        case Direction::left:
            cube.at(x).at(4 - z).at(y - 1).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y - 1));
            cube.at(x).at(4 - z).at(y - 2).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y - 2));
            cube.at(x).at(4 - z).at(y + 1).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y + 1));
            break;
        case Direction::right:
            cube.at(x).at(4 - z).at(y + 1).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y + 1));
            cube.at(x).at(4 - z).at(y + 2).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y + 2));
            cube.at(x).at(4 - z).at(y - 1).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y - 1));
            break;
        case Direction::up:
            cube.at(x).at(4 - (z + 1)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z + 1)).at(y));
            cube.at(x).at(4 - (z + 2)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z + 2)).at(y));
            cube.at(x).at(4 - (z - 1)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z - 1)).at(y));
            break;
        case Direction::down:
            cube.at(x).at(4 - (z - 1)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z - 1)).at(y));
            cube.at(x).at(4 - (z - 2)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z - 2)).at(y));
            cube.at(x).at(4 - (z + 1)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z + 1)).at(y));
            break;
        case Direction::front:
            cube.at(x + 1).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x + 1).at(4 - z).at(y));
            cube.at(x + 2).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x + 2).at(4 - z).at(y));
            cube.at(x - 1).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x - 1).at(4 - z).at(y));
            break;
        case Direction::back:
            cube.at(x - 1).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x - 1).at(4 - z).at(y));
            cube.at(x - 2).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x - 2).at(4 - z).at(y));
            cube.at(x + 1).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x + 1).at(4 - z).at(y));
            break;

        default:
            std::cout << "Direction in " << __func__ << " does not exist.\n";
            exit(1);
            break;
        }
        switch (p->get_nose_dir())
        {
        case Direction::left:
            cube.at(x).at(4 - z).at(y - 1).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y - 1));
            break;
        case Direction::right:
            cube.at(x).at(4 - z).at(y + 1).val = ID;
            update_neighbours(cube.at(x).at(4 - z).at(y + 1));
            break;
        case Direction::up:
            cube.at(x).at(4 - (z + 1)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z + 1)).at(y));
            break;
        case Direction::down:
            cube.at(x).at(4 - (z - 1)).at(y).val = ID;
            update_neighbours(cube.at(x).at(4 - (z - 1)).at(y));
            break;
        case Direction::front:
            cube.at(x + 1).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x + 1).at(4 - z).at(y));
            break;
        case Direction::back:
            cube.at(x - 1).at(4 - z).at(y).val = ID;
            update_neighbours(cube.at(x - 1).at(4 - z).at(y));
            break;

        default:
            std::cout << "Direction in " << __func__ << " does not exist.\n";
            exit(1);
            break;
        }
    }

    void Puzzle::remove_piece(std::unique_ptr<Piece> &p)
    {
        size_t x = p->get_x_pos();
        size_t y = p->get_y_pos();
        size_t z = p->get_z_pos();

        cube.at(x).at(4 - z).at(y).val = 0;

        switch (p->get_tail_dir())
        {
        case Direction::left:
            cube.at(x).at(4 - z).at(y - 1).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y - 1));
            cube.at(x).at(4 - z).at(y - 2).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y - 2));
            cube.at(x).at(4 - z).at(y + 1).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y + 1));
            break;
        case Direction::right:
            cube.at(x).at(4 - z).at(y + 1).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y + 1));
            cube.at(x).at(4 - z).at(y + 2).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y + 2));
            cube.at(x).at(4 - z).at(y - 1).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y - 1));
            break;
        case Direction::up:
            cube.at(x).at(4 - (z + 1)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z + 1)).at(y));
            cube.at(x).at(4 - (z + 2)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z + 2)).at(y));
            cube.at(x).at(4 - (z - 1)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z - 1)).at(y));
            break;
        case Direction::down:
            cube.at(x).at(4 - (z - 1)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z - 1)).at(y));
            cube.at(x).at(4 - (z - 2)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z - 2)).at(y));
            cube.at(x).at(4 - (z + 1)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z + 1)).at(y));
            break;
        case Direction::front:
            cube.at(x + 1).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x + 1).at(4 - z).at(y));
            cube.at(x + 2).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x + 2).at(4 - z).at(y));
            cube.at(x - 1).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x - 1).at(4 - z).at(y));
            break;
        case Direction::back:
            cube.at(x - 1).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x - 1).at(4 - z).at(y));
            cube.at(x - 2).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x - 2).at(4 - z).at(y));
            cube.at(x + 1).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x + 1).at(4 - z).at(y));
            break;

        default:
            std::cout << "Direction in " << __func__ << " does not exist.\n";
            exit(1);
            break;
        }
        switch (p->get_nose_dir())
        {
        case Direction::left:
            cube.at(x).at(4 - z).at(y - 1).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y - 1));
            break;
        case Direction::right:
            cube.at(x).at(4 - z).at(y + 1).val = 0;
            update_neighbours(cube.at(x).at(4 - z).at(y + 1));
            break;
        case Direction::up:
            cube.at(x).at(4 - (z + 1)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z + 1)).at(y));
            break;
        case Direction::down:
            cube.at(x).at(4 - (z - 1)).at(y).val = 0;
            update_neighbours(cube.at(x).at(4 - (z - 1)).at(y));
            break;
        case Direction::front:
            cube.at(x + 1).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x + 1).at(4 - z).at(y));
            break;
        case Direction::back:
            cube.at(x - 1).at(4 - z).at(y).val = 0;
            update_neighbours(cube.at(x - 1).at(4 - z).at(y));
            break;

        default:
            std::cout << "Direction in " << __func__ << " does not exist.\n";
            exit(1);
            break;
        }
    }

    void Puzzle::reset_piece(std::unique_ptr<Piece> &p)
    {
        p->reset_configuration();
        p->set_x_pos(0);
        p->set_y_pos(0);
        p->set_z_pos(0);
    }

    void Puzzle::forward_track()
    {
        if (cur_piece < 10)
        {
            if (is_free(pieces.at(cur_piece)))
            {
                if (pieces.at(cur_piece)->next_configuration())
                {
                    if (does_piece_fit(pieces.at(cur_piece)))
                    {
                        put_piece(pieces.at(cur_piece));
                        cur_piece++;
                        forward_track();
                    }
                    else
                    {
                        forward_track();
                    }
                }
                else
                {
                    pieces.at(cur_piece)->reset_configuration();
                    if (next_step(pieces.at(cur_piece)))
                    {
                        forward_track();
                    }
                    else
                    {
                        reset_piece(pieces.at(cur_piece));
                        cur_piece--;
                        remove_piece(pieces.at(cur_piece));
                        forward_track();
                    }
                }
            }
            else
            {
                if (next_step(pieces.at(cur_piece)))
                {
                    forward_track();
                }
                else
                {
                    reset_piece(pieces.at(cur_piece));
                    cur_piece--;
                    remove_piece(pieces.at(cur_piece));
                    forward_track();
                }
            }
        }
        else
        {
            std::cout << "Result: \n";
            print();
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
                    std::cout << kt.criticalness<< "\t";
                }
                std::cout << "\n\n";
            }
            std::cout << "----------------------------------------\n";
        }
    }
} // namespace cube
