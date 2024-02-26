#include "mover.hpp"

namespace cube
{

    Mover::Mover()
    {
        S = std::make_unique<Shapes>();
    }

    void Mover::init_cube(const double &N)
    {
        S->cube(N);
    }

    void Mover::init_pyramid(const double &base, const double &height)
    {
        S->pyramid(base, height);
    }

    void Mover::rot_x(const double &sign)
    {
        Vec3D axis(1, 0, 0);
        S->rotate(sign * dtheta, axis);
    }
    void Mover::rot_y(const double &sign)
    {
        Vec3D axis(0, 1, 0);
        S->rotate(sign * dtheta, axis);
    }
    void Mover::rot_z(const double &sign)
    {
        Vec3D axis(0, 0, 1);
        S->rotate(sign * dtheta, axis);
    }

    void Mover::animate()
    {
        std::unique_ptr<Drawer> D = std::make_unique<Drawer>();
        Vec3D axis(1, 1, 0);
        S->rotate(M_PI / 4, axis);
        D->draw_shape(S);
        D->show();
        using namespace std::this_thread;     // sleep_for, sleep_until
        using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
        using std::chrono::system_clock;
        while (1)
        {
            sleep_for(10ns);
            sleep_until(system_clock::now() + 0.1s);
            rot_z(-1.);
            D->clear_frame();
            D->draw_shape(S);
            D->show();
        }
    }

    void Mover::control()
    {
        std::unique_ptr<Drawer> D = std::make_unique<Drawer>();

        int direction;

        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        D->draw_shape(S);
        D->show();

        while (1)
        {
            direction = getch();

            switch (direction)
            {
            case KEY_UP:
                rot_y(1.);
                D->clear_frame();
                D->draw_shape(S);
                D->show();
                break;
            case KEY_DOWN:
                rot_y(-1.);
                D->clear_frame();
                D->draw_shape(S);
                D->show();
                break;
            case KEY_LEFT:
                rot_z(1.);
                D->clear_frame();
                D->draw_shape(S);
                D->show();
                break;
            case KEY_RIGHT:
                rot_z(-1.);
                D->clear_frame();
                D->draw_shape(S);
                D->show();
                break;
            default:
                endwin();
                exit(0);
                break;
            }
        }
    }
} // namespace cube
