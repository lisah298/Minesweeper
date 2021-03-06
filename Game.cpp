// Using code of sheet 10 (habe auch Teile meines Codes genommen)
#include "Command.hpp"
#include "Grid.hpp"
#include "Board.hpp"
#include "Terminal_output.hpp"
#include "Utiities.hpp"
#include "Types.hpp"

int main()
{
    Coordinates c = {2, 2};
    GridSize size{4U, 8U};
    size_t mines = 6;
    // Grid board = Board(size, mines);
    Board board(size, mines);
    Grid grid(size);
    Metadata metadata{size, mines};
    TerminalPrinter display{};
    display.print(board, metadata);

    grid(0, 0) = Tile_type::revealed_mine_tile; //test if Tile_type definition works
    grid(0, 1) = '*';
    grid(0, 2) = 'L';
    grid(0, 3) = 'W';
    grid(0, 4) = '@';
    grid(1, 0) = '1';
    grid(1, 1) = '2';
    grid(1, 2) = '3';
    grid(1, 3) = '4';
    grid(1, 4) = '5';
    grid(1, 5) = '6';
    grid(1, 6) = '7';
    grid(1, 7) = '8';
    grid(2, 7) = '0';
    display.print(grid, metadata);
    //count_type_of_tile_among_adjacent_ones(c, '2', grid);
    Command act = Command::next_command(size);
    std::cout << act.action() << "  (" << act.coordinates().x << ", " << act.coordinates().y << ")\n\n";
    return 0;
}