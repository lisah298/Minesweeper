#include "Types.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Grid
{
private:
    std::vector<std::vector<Tile>> tiles;
    const Tile grey = '@';
    const Tile orange = 'A';
    const Tile darkred = '*';
    const Tile red = 'L';
    const Tile green = 'W';
    const Tile white = '0';
    const Tile one = '1';
    const Tile two = '2';
    const Tile three = '3';
    const Tile four = '4';
    const Tile five = '5';
    const Tile six = '6';
    const Tile seven = '7';
    const Tile eight = '8';

public:
    Grid(const GridSize &size) : tiles(size.rows, std::vector<Tile>(size.columns, '@')){
                                     // Teste, ob rows und columns richtig übergeben werden
                                     //cout << "rows: " << size.rows << " columns: " << size.columns << endl;
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

    void print(const Grid &grid, const Metadata &metadata)
    {
        size_t cols = metadata.grid_size.columns;
        //printe erste Zeile mit Spaltennummern
        cout
            << "    ";
        for (int i = 0; i < metadata.grid_size.columns; ++i)
        { //number with 3 spaces
            cout << i << "   ";
        }
        cout << endl;
        cout << "   " << string(4 * cols, '=') << endl;
        for (size_t row = 0; row < metadata.grid_size.rows; ++row)
        {
            // print row at beginning
            cout << row << " | ";
            for (size_t column = 0; column < metadata.grid_size.columns; ++column)
            {
                cout << grid(row, column);
                cout << " | ";
            }

            cout << endl;
            cout << "   " << string(4 * cols, '=') << endl; // neue Zeile mit -
        }
    }
};
