#include "Utiities.hpp"

bool is_tile_inside_grid(const Coordinates &coords, const GridSize &gridsize)
{ //eigentlich ist es überflüssig zu checken, ob die Werte größer null sind, da wird mit size_t asrbeiten
    if (coords.x < gridsize.columns && coords.x >= 0 && coords.y >= 0 && coords.y < gridsize.rows)
    {
        return true;
    }
    else
    {
        return false;
    }
};

std::vector<Coordinates> next_neighbours(const Coordinates &coords, const GridSize &gridsize)
{
    std::vector<Coordinates> neighbours{};
    //Koordinaten in ints kopieren
    int x_coord = coords.x;
    int y_coord = coords.y;
    //iterate over x values
    for (int i = -1; i <= 1; i++)
    { //Hilfsvariable als int, weil coords.x ist ein size_t
        int helpi_x = x_coord + i;
        if (helpi_x >= 0)
        {
            size_t x = x_coord + i;
            //iteriere über y
            for (int j = -1; j <= 1; j++)
            {
                int helpi_y = y_coord + j;
                if (helpi_y > 0)
                {
                    size_t y = coords.y + j;
                    Coordinates toCheck = {x, y};
                    //prüfe, ob die Nachbarn im Grid sind
                    if (is_tile_inside_grid(toCheck, gridsize) == 1)
                    { //prüfe, ob die Koordinate nicht die übergebene ist, also das Zenter
                        if (!(toCheck.x == coords.x && toCheck.y == coords.y))
                        { //zur Liste hinzufügen
                            neighbours.push_back(toCheck);
                        }
                    }
                }
            }
        }
    };
    //print coordiantes to check
    /* for (const auto &val : neighbours)
    {
        std::cout << "x: " << val.x << ". y: " << val.y << "\n";
    }; */
    return neighbours;
};

unsigned int
count_type_of_tile_among_adjacent_ones(const Coordinates &coords, const Tile &tile, const Grid &grid)
{ //get neighbours
    std::vector<Coordinates> adjactents = next_neighbours(coords, grid.size());
    //check type of neighbour types while looping through neigbours
    int counter = 0;
    for (const Coordinates &elem : adjactents)
    {
        if (grid(elem) == tile)
        {
            counter += 1;
        };
    }
    std::cout << counter << " neighbour(s) with " << tile << " at (" << coords.x << "," << coords.y << ')' << std::endl;
    return counter;
};