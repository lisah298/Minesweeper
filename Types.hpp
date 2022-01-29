#pragma once
#include <array>

using size_t = std::size_t;
using Tile = char;

struct GridSize
{
    size_t rows{4};
    size_t columns{6};
};

struct Coordinates
{
    size_t x{static_cast<size_t>(-1)};
    size_t y{static_cast<size_t>(-1)};
};

struct Metadata
{
    GridSize grid_size{};
    size_t n_mines{grid_size.rows * grid_size.columns / 5};
};