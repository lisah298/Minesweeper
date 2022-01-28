#include "Terminal_output.hpp"
#include <iostream>

int main()
{
    std::cout << "\033[33;46m Minesweeper \033[0m\n";
    GridSize gridsize{3, 8};
    Metadata metadata{gridsize, 2};
    Grid grid{gridsize};
    grid.print(grid, metadata);
};