
#include "Board.hpp"

Board::Board(const GridSize &size, size_t numMines) : Grid(size), n_mines(numMines)
{
    // 1. Prüfe ob numMines < number of tiles
    size_t n_tiles = nCols() * nRows();
    if (numMines > n_tiles)
    {
        std::cout << "LOGIC ERROR: number of mines is bigger than number of tiles" << std::endl;
        std::abort();
    }
    else
    { // Test, um Zahl der Minen anzuzeigen
        std::cout << numMines << " number of mines are valid" << std::endl;
        tiles.resize(nRows());
        // 2. fill board with empty tiles by calling the constructor
        for (auto &row : tiles)
        {
            row.resize(nCols());
            std::fill(std::begin(row), std::end(row), '0');
        }
    }

    // 3. randomly distirbute the mines on the grid
    Board::distribute_mines();
    // 4. fill the safe tiles with the number of adjactent mines
};

void Board::distribute_mines()
{
    size_t bomb_counter = 0;
    for (int i = 0; bomb_counter < n_mines; i++)
    {
        // std::cout << i << '\n';
        auto seed = std ::chrono ::system_clock ::now().time_since_epoch().count();
        std ::default_random_engine generator(seed);
        // number for x
        std ::uniform_int_distribution<size_t> getInteger(0, nCols() - 1);
        size_t Number_x = getInteger(generator);
        // std::cout << "x: " << Number_x << '\t';
        //  number for y
        std ::uniform_int_distribution<size_t> getInteger2(0, nRows() - 1);
        size_t Number_y = getInteger2(generator);
        // std::cout << "y: " << Number_y << '\n';
        Coordinates bomb{Number_x, Number_y};
        // tiles(bomb) = '*';
        if (tiles.at(Number_y).at(Number_x) != '*')
        {
            // eigentlich sollte ich hier meine Operator overload nutzen, aber das funktioniert irgendwie nicht
            tiles.at(Number_y).at(Number_x) = '*';
            bomb_counter++;
        };
    }
};
void Board::set_adjactent_mines_numbers()
{
    std::cout << " Yeah" << std::endl;
};