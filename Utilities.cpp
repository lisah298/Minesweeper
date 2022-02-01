#include "Utiities.hpp"

bool is_tile_inside_grid(const Coordinates &coords, const GridSize &gridsize)
{
    if (coords.x < gridsize.columns && coords.y < gridsize.rows)
    {
        std::cout << "True" << std::endl;
        return true;
    }
    else
    {
        std::cout << "False" << std::endl;
        return false;
    }
};