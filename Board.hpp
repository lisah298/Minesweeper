#pragma once

#include "Grid.hpp"
#include <random>
#include <chrono>
#include <vector>

class Board final : public Grid
{
public:
    Board(const GridSize &, size_t);

private:
    size_t n_mines;
    void distribute_mines();
    void set_adjactent_mines_numbers();
};