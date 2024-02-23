#include "cube.hpp"

namespace cube
{

#define SETEDGE(corner1, corner2, tempedge)                         \
    set_line(*corners.at(corner1), *corners.at(corner2), tempedge); \
    edge.push_back(std::move(tempedge));

    Cube::Cube(std::uint16_t size)
    {
        assert(size != 0u);
        CUBE_SIZE = size;
        init_corners();
        init_edges();
    }

    void Cube::init_corners()
    {
        for (size_t i = 0; i < 8; i++)
        {
            corners.push_back(std::make_unique<Vec3D>());
        }
        corners.at(0)->set_xyz(1., -1., 1.);
        corners.at(1)->set_xyz(1., 1., 1.);
        corners.at(2)->set_xyz(1., -1., -1.);
        corners.at(3)->set_xyz(1., 1., -1.);
        corners.at(4)->set_xyz(-1., -1., 1.);
        corners.at(5)->set_xyz(-1., 1., 1.);
        corners.at(6)->set_xyz(-1., -1., -1.);
        corners.at(7)->set_xyz(-1., 1., -1.);
    }

    void Cube::print_corners()
    {
        for (size_t i = 0; i < 8; i++)
        {
            std::cout << "Corner " << i + 1 << ":\n";
            corners.at(i)->print();
        }
    }

    void Cube::set_line(Vec3D &p1, Vec3D &p2, vset &line)
    {
        assert(line.size() == 0);

        Vec3D vtemp;
        v_add(vtemp, p1, vtemp);

        Vec3D delta;
        v_sub(p2, p1, delta);
        v_div_s(delta, (double)(CUBE_SIZE - 1));

        for (std::uint16_t i = 1u; i < CUBE_SIZE - 1; i++)
        {
            v_add(vtemp, delta, vtemp);
            line.push_back(std::make_unique<Vec3D>());
            v_add(*line.at(i - 1), vtemp, *line.at(i - 1));
        }

        v_add(vtemp, delta, vtemp);
        assert(is_same(vtemp, p2));
    }

    void Cube::init_edges()
    {
        vset tempedge;
        SETEDGE(0, 1, tempedge)
        SETEDGE(0, 2, tempedge)
        SETEDGE(1, 3, tempedge)
        SETEDGE(2, 3, tempedge)
        SETEDGE(0, 4, tempedge)
        SETEDGE(2, 6, tempedge)
        SETEDGE(1, 5, tempedge)
        SETEDGE(3, 7, tempedge)
        SETEDGE(4, 5, tempedge)
        SETEDGE(4, 6, tempedge)
        SETEDGE(5, 7, tempedge)
        SETEDGE(6, 7, tempedge)

        print_line(edge.at(11));
    }

    void Cube::print_line(vset &line)
    {
        std::cout << "Line:\n";
        for (size_t i = 0; i < line.size(); i++)
        {
            line.at(i)->print();
        }
    }
} // namespace cube
