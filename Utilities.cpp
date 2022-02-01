#include "Utiities.hpp"

bool is_tile_inside_grid(const Coordinates &coords, const GridSize &gridsize)
{
    if (coords.x < gridsize.columns && coords.x >= 0 && coords.y >= 0 && coords.y < gridsize.rows)
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

std::vector<Coordinates> next_neighbours(const Coordinates &coords, const GridSize &gridsize)
{
    std::vector<Coordinates> neighbours;
    std::vector<int> helpi = {-1, 0, 1};
    std::cout << "Here i am" << std::endl;
    //iterate over x values
    for (const auto &value : helpi)
    {
        std::cout << value << std::endl;
        size_t x = coords.x + value;
        //iterate over y
        for (const auto &value2 : helpi)
        {
            std::cout << value2 << std::endl;
            size_t y = coords.y + value2;
            Coordinates toCheck{x, y};
            std::cout << "check funct" << is_tile_inside_grid(toCheck, gridsize) << std::endl;
            //check whether neighbors are in grid
            if (is_tile_inside_grid(toCheck, gridsize))
            { //checke whether coordinates are neigbour or center
                if (!(toCheck.x == coords.x && toCheck.y == coords.y))
                {
                    std::cout << "is True" << std::endl;
                    neighbours.push_back(toCheck);
                }
            }
        }
    };
    //print coordiantes to check
    /* for (const auto &val : neighbours)
    {
        std::cout << "x: " << val.x << ". y: " << val.y << "\n";
    }; */
};