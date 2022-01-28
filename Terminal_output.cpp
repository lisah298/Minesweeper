#include "Terminal_output.hpp"
#include "Command.hpp"
#include <iostream>

int main()
{
    GridSize gridsize{3, 8};
    Metadata metadata{gridsize, 2};
    Grid grid{gridsize};
    TerminalPrinter t{};
    t.print(grid, metadata);
};