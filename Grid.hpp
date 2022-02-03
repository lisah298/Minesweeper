#pragma once

#include "Types.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Grid
{
protected:
    std::vector<std::vector<Tile>> tiles;
    size_t nRows() const { return tiles.size(); };
    size_t nCols() const { return tiles[0].size(); };

public:
    explicit Grid(const GridSize &size) : tiles(size.rows, std::vector<Tile>(size.columns, '-')){};
    virtual ~Grid(){};
    GridSize size() const { return {nRows(), nCols()}; }
    const Tile &
    operator()(Coordinates coords) const
    {
        return tiles[coords.x][coords.y];
    };

    Tile &operator()(Coordinates coords)
    {
        return tiles[coords.x][coords.y];
    };
    const Tile &operator()(size_t row, size_t column) const
    {
        return tiles.at(row).at(column);
    };
    Tile &operator()(size_t row, size_t column)
    {
        return tiles[row][column];
    };
};