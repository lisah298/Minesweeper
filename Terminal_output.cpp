#include "Terminal_output.hpp"
#include "Grid.hpp"

void TerminalPrinter::print(const Grid &grid, const Metadata &metadata) const
{
    auto size = grid.size();
    print_metadata(metadata);
    endline();
    print_numbers(size.columns);
    for (size_t i = 0; i < size.rows; i++)
    {
        print_line_of_equals(size.columns);
        std::cout << "  " << std::setw(2) << i << " ";
        for (size_t j = 0; j < size.columns; j++)
        {
            std::cout << "| " << decorate_tile(grid(i, j)) << " ";
        }
        std::cout << "|  " << std::setw(2) << i;
        endline();
    }
    print_line_of_equals(size.columns);
    print_numbers(size.columns);
    endline();
}

void TerminalPrinter::print_metadata(const Metadata &metadata) const
{
    endline();
    std::cout << std::setw(30) << "   Number of Mines: " << metadata.n_mines << '\n';
    endline();
}

std::string TerminalPrinter::decorate_tile(const Tile tile) const
{
    std::string out{};
    switch (tile)
    {
    case '1':
        return "\033[38;5;4m1\033[0m";
        break;
    case '2':
        return "\033[38;5;10m2\033[0m";
        break;
    case '3':
        return "\033[38;5;9m3\033[0m";
        break;
    case '4':
        return "\033[38;5;135m4\033[0m";
        break;
    case '5':
        return "\033[38;5;130m5\033[0m";
        break;
    case '6':
        return "\033[38;5;14m6\033[0m";
        break;
    case '7':
        return "\033[38;5;15m7\033[0m";
        break;
    case '8':
        return "\033[38;5;152m8\033[0m";
        break;
    case '@':
        return "\033[48;5;248m \033[0m";
        break;
    case 'A':
        return "\033[48;5;208m \033[0m";
        break;
    case 'W':
        return "\033[48;5;2m \033[0m";
        break;
    case 'L':
        return "\033[48;5;9m\033[38;5;0m \033[0m";
        break;
    case '*':
        return "\033[48;5;1m\033[38;5;0m \033[0m";
        break;
    case '0':
        return "\033[48;5;15m\033[38;5;0m \033[0m";
        break;
    default:
        out = tile;
        break;
    }
    return out;
}

void TerminalPrinter::indent() const { std::cout << "     "; }

void TerminalPrinter::endline() const { std::cout << "\n"; }

void TerminalPrinter::print_numbers(size_t nCols) const
{
    indent();
    for (size_t i = 0U; i < nCols; i++)
        std::cout << " " << std::setw(2) << i << " ";
    endline();
}

void TerminalPrinter::print_line_of_equals(size_t nCols) const
{
    indent();
    for (size_t i = 0U; i < nCols; i++)
        std::cout << "====";
    endline();
}