#include "Terminal_output.hpp"
#include "Command.hpp"
#include <iostream>

int main()
{ //Exercise 1 and 2 Test Terminal print
    GridSize gridsize{8, 8};
    Metadata metadata{gridsize, 2};
    Grid grid{gridsize};
    TerminalPrinter t{};
    t.print(grid, metadata);

    //Exercise 3
    Command c{};
    c.read();
    c.validate(gridsize);
};