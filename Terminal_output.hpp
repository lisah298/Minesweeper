#include "Types.hpp"
#include <vector>
#include <iostream>

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
                                     // Teste, b rows und columns richtig übergeben werden
                                     //cout << "rows: " << size.rows << " columns: " << size.columns << endl;
                                 };
    /*  Grid(const GridSize &size) : tiles{}
    {
        // create rows
        tiles.resize(size.rows);
        for (auto &row : tiles)
        {
            //cout << "Hi, ich bin im Konstrukotr";
            // resize each row to have number of columns elements, each being '@'
            row.resize(size.columns, grey);
        }
    }; */
    const Tile &operator()(Coordinates coords) const
    {
        return tiles[coords.x][coords.y];
    };

    Tile &operator()(Coordinates coords)
    {
        return tiles[coords.x][coords.y];
    };
    const Tile &operator()(size_t row, size_t column) const
    { //Bug beim return
        //cout << "Ich bin im operator" << endl;
        //cout << row << endl;
        //cout << column << endl;
        return tiles.at(row).at(column);
    }
    Tile &operator()(size_t row, size_t column)
    {
        return tiles[row][column];
    }

    //Getter
    //size_t Grid::num_rows() const
    //{
    //    return Gridsize &size.rows;
    //}

    /* void print(const Grid &grid, const Metadata &metadata)
    {
        for (auto &x : tiles)
        {
            std::cout << "Hallo";
            for (auto &y : x)
            {

                std::cout << y;
                std::cout << "HI";
            };
            std::cout << '\n';
        };
    }; */

    void print(const Grid &grid, const Metadata &metadata)
    {

        for (size_t row = 0; row < metadata.grid_size.rows; ++row)
        {

            for (size_t column = 0; column < metadata.grid_size.columns; ++column)
            {
                cout << grid(row, column);
            }
            cout << endl; // neue Zeile
        }
    }
};
