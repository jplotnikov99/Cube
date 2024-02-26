#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "drawer.hpp"

namespace cube
{
    class Mover
    {
    private:
        const double dtheta = 1 / (20 * M_PI);
        std::unique_ptr<Shapes> S = std::make_unique<Shapes>();

    public:
        void init_cube(const double &N);

        void rot_x(const double &sign);
        void rot_y(const double &sign);
        void rot_z(const double &sign);


        void animate();
        void control();

        Mover();
        ~Mover(){};
    };

} // namespace cube
