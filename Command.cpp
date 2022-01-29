#include "Command.hpp"
#include <cstddef>
#include <iostream>
#include <memory>

Command Command::next_command(const GridSize &size)
{
    Command command{};
    do
    {
        command.get_command();
    } while (!command.is_command_valid(size));
    return command;
}

Coordinates Command::coordinates() const
{
    if (_coordinate)
        return *_coordinate;
    else
    {
        std::cout << "\n LOGIC ERROR: Trying retrieving coordinates of help or quit action!\n";
        std::abort();
    }
};

void Command::get_command()
{
    std::cout << "  Action, row and column (h for help): ";
    std::cin >> _action;
    if (_action != 'h' && _action != 'q')
    {
        _coordinate = std::make_unique<Coordinates>();
        std::cin >> _coordinate->x >> _coordinate->y;
    }
}

bool Command::is_command_valid(const GridSize &size) const
{
    if (_action == 'h' || _action == 'q')
        return true;
    if (_action != 'r' && _action != 'a' && _action != 'd')
        return false;
    if (!_coordinate)
    {
        std::cout << "\n LOGIC ERROR: Command validation has no coordinates for action requiring some!\n";
        std::abort();
    }
    if (!(_coordinate->x >= 0 && _coordinate->x < size.rows))
        return false;
    if (!(_coordinate->y >= 0 && _coordinate->y < size.columns))
        return false;
    return true;
}