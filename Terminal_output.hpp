#include "Types.hpp"
#include "Grid.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Grid;

class TerminalPrinter
{
public:
    void print(const Grid &grid, const Metadata &metadata)
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

private:
    //string decorate_tile2(const Tile &tile);
    void print_numbers(size_t num_columns)
    {
        cout
            << "    ";
        for (int i = 0; i < num_columns; ++i)
        { //number with 3 spaces
            cout << i << "   ";
        }
        cout << endl;
    };
    void print_line_of_equals(size_t num_columns)
    {
        cout << "  =" << string(4 * num_columns, '=') << endl;
    };

    string decorate_tile(const Tile &tile)
    {
        switch (tile)
        {
        case '1':
            return "\033[38;5;4m"
                   " 1 "
                   "\033[0m";
        case '2':
            return "\033[38;5;22m"
                   " 2 "
                   "\033[0m";
        case '3':
            return "\033[38;5;124m"
                   " 3 "
                   "\033[0m";
        case '4':
            return "\033[38;5;17m"
                   " 4 "
                   "\033[0m";
        case '5':
            return "\033[38;5;52m"
                   " 5 "
                   "\033[0m";
        case '6':
            return "\033[38;5;29m"
                   " 6 "
                   "\033[0m";
        case '7':
            return "\033[38;5;54m"
                   " 7 "
                   "\033[0m";
        case '8':
            return "\033[38;5;8m"
                   " 8 "
                   "\033[0m";
        case '@':
            return "\033[48;5;243m"
                   "   "
                   "\033[0m";
        case 'A':
            return "\033[48;5;202m"
                   "   "
                   "\033[0m";
        case '*':
            return "\033[48;5;124m"
                   "   "
                   "\033[0m";
        case 'L':
            return "\033[48;5;196m"
                   "   "
                   "\033[0m";
        case 'W':
            return "\033[48;5;10m"
                   "   "
                   "\033[0m";

        case '0':
            return "\033[48;5;15m"
                   "   "
                   "\033[0m";
        }
    };
};