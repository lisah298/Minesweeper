#include "Types.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Grid
{
private:
    std::vector<std::vector<Tile>> tiles;

public:
    Grid(const GridSize &size) : tiles(size.rows, std::vector<Tile>(size.columns, 'W')){
                                     // Teste, ob rows und columns richtig übergeben werden
                                     //cout << "rows: " << size.rows << " columns: " << size.columns << endl;
                                     //cout << grey << endl;
                                 };

    const Tile &operator()(Coordinates coords) const
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
    }
    Tile &operator()(size_t row, size_t column)
    {
        return tiles[row][column];
    }
};