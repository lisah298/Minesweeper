#include "Terminal_output.hpp"
#include <iostream>

int main()
{
    GridSize gridsize{3, 8};
    Metadata metadata{gridsize, 2};
    Grid grid{gridsize};
    grid.print(grid, metadata);
};