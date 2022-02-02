#pragma once
#include "Types.hpp"
#include <iostream>
#include <vector>
#include "Grid.hpp"
bool is_tile_inside_grid(const Coordinates &, const GridSize &);
std::vector<Coordinates> next_neighbours(const Coordinates &, const GridSize &);
unsigned int count_type_of_tile_among_adjacent_ones(const Coordinates &,
                                                    const Tile &, const Grid &);