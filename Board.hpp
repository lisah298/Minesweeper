#pragma once

#include "Grid.hpp"
#include "Utiities.hpp"
#include <string>
#include <random>
#include <chrono>
#include <vector>

class Board final : public Grid
{
public:
    Board(const GridSize &, size_t);
    Board(const Grid &tiles) : Grid(tiles){};

private:
    size_t n_mines;
    void distribute_mines();
    void set_adjactent_mines_numbers();
};