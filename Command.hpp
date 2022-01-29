#pragma once

#include <memory>

#include "Types.hpp"

using Action = char;

class Command
{
public:
    static Command next_command(const GridSize &);

    Action action() const { return _action; }
    Coordinates coordinates() const;

private:
    void get_command();
    bool is_command_valid(const GridSize &) const;

    Action _action{'u'};
    std::unique_ptr<Coordinates> _coordinate{nullptr};
};