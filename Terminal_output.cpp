#include "Terminal_output.hpp"
#include "Command.hpp"
#include <iostream>

void TerminalPrinter::print(const Grid &grid, const Metadata &metadata)
{
    size_t cols = metadata.grid_size.columns;
    //printe erste Zeile mit Spaltennummern
    print_numbers(cols);
    print_line_of_equals(cols);
    for (size_t row = 0; row < metadata.grid_size.rows; ++row)
    {
        // print row at beginning
        cout << row << " |";
        for (size_t column = 0; column < metadata.grid_size.columns; ++column)
        {
            cout << decorate_tile(grid(row, column));
            cout << "|";
        }

        cout << ' ' << row << endl;
        print_line_of_equals(cols);
    }
    print_numbers(cols);
};

int main()
{ //Exercise 1 and 2 Test Terminal printer
    GridSize gridsize{8, 8};
    Metadata metadata{gridsize, 2};
    Grid grid{gridsize};
    TerminalPrinter t{};
    t.print(grid, metadata);

    //Exercise 3
    Command c{};
    c.next_command(gridsize);
};