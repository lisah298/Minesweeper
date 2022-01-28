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
    size_t x{0};
    size_t y{0};
};

struct Metadata
{
    GridSize grid_size{1, 1};
    size_t n_mines{1};
};