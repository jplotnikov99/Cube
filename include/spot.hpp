#pragma once
#include <iostream>
#include <vector>

namespace cube
{
    struct Spot
    {
        size_t val;
        size_t criticalness;
        size_t N_neighbours;
        std::vector<std::vector<size_t>> neighbours;
    };

    bool operator!=(const Spot a, const size_t b);

} // namespace cube
