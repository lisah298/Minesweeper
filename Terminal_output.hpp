#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Types.hpp"
using namespace std;

class Grid;
class Mask;

class TerminalPrinter
{
public:
    void print(const Grid &, const Metadata &) const;

private:
    void print_numbers(size_t) const;
    void print_line_of_equals(size_t) const;
    std::string decorate_tile(const Tile) const;
    void print_metadata(const Metadata &) const;
    void indent() const;
    void endline() const;
};