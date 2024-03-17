#include "shapes.hpp"

namespace cube
{

    size_t Shapes::get_N_lines()
    {
        return lines.size();
    }

    void Shapes::cube(const double &size)
    {
        assert(size > 0);

        std::vector<std::unique_ptr<Vec3D>> corners;
        corners.push_back(std::make_unique<Vec3D>(size, size, size));
        corners.push_back(std::make_unique<Vec3D>(size, size, -size));
        corners.push_back(std::make_unique<Vec3D>(size, -size, size));
        corners.push_back(std::make_unique<Vec3D>(size, -size, -size));
        corners.push_back(std::make_unique<Vec3D>(-size, size, size));
        corners.push_back(std::make_unique<Vec3D>(-size, size, -size));
        corners.push_back(std::make_unique<Vec3D>(-size, -size, size));
        corners.push_back(std::make_unique<Vec3D>(-size, -size, -size));

        lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(1)));
        lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(2)));
        lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(4)));
        lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(5)));
        lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(3)));
        lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(3)));
        lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(6)));
        lines.push_back(std::make_unique<Line>(*corners.at(3), *corners.at(7)));
        lines.push_back(std::make_unique<Line>(*corners.at(4), *corners.at(5)));
        lines.push_back(std::make_unique<Line>(*corners.at(4), *corners.at(6)));
        lines.push_back(std::make_unique<Line>(*corners.at(5), *corners.at(7)));
        lines.push_back(std::make_unique<Line>(*corners.at(6), *corners.at(7)));
    }

    void Shapes::pyramid(const double &base, const double &height)
    {
        assert(base > 0);
        assert(height > 0);

        std::vector<std::unique_ptr<Vec3D>> corners;

        corners.push_back(std::make_unique<Vec3D>(base, base, 0));
        corners.push_back(std::make_unique<Vec3D>(base, -base, 0));
        corners.push_back(std::make_unique<Vec3D>(-base, base, 0));
        corners.push_back(std::make_unique<Vec3D>(-base, -base, 0));
        corners.push_back(std::make_unique<Vec3D>(0, 0, height));

        lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(1)));
        lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(2)));
        lines.push_back(std::make_unique<Line>(*corners.at(0), *corners.at(4)));
        lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(3)));
        lines.push_back(std::make_unique<Line>(*corners.at(1), *corners.at(4)));
        lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(3)));
        lines.push_back(std::make_unique<Line>(*corners.at(2), *corners.at(4)));
        lines.push_back(std::make_unique<Line>(*corners.at(3), *corners.at(4)));
    }

    void Shapes::rotate(const double &angle, Vec3D &rot_axis)
    {
        for (auto &it : lines)
        {
            it->rotate(angle, rot_axis);
        }
    }

} // namespace cube
