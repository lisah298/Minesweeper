#include "Terminal_output.hpp"
#include <iostream>

int main()
{
    GridSize gridsize{5, 5};
    Metadata metadata{gridsize, 2};
    Grid grid{gridsize};
    grid.print(grid, metadata);
};