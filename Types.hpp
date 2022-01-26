#pragma once
#include <array>

using size_t = std::size_t;
using Tile = char;

struct GridSize
{
    size_t rows{0};
    size_t columns{0};
};

struct Coordinates
{
    int x{0};
    int y{0};
};

struct Metadata
{
    GridSize gridsize{0, 0};
    size_t n_tiles{1};
};