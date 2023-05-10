#include "tile.h"

#include <iomanip>

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    if (tile.is_empty())
    {
        out << "    ";
    }
    else
    {
        out << std::setw(3) << std::to_string(tile.get_num()) << ' ';
    }

    return out;
}