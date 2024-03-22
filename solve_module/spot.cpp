#include "spot.hpp"

namespace cube
{
    bool operator!=(const Spot a, const size_t b)
    {
        return a.val != b;
    }

} // namespace cube
