#pragma once

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
    void print(const Grid &grid, const Metadata &metadata);

private:
    void print_numbers(size_t) const;
    void print_line_of_equals(size_t) const;
    string decorate_tile(const Tile &tile);
};