#include "tile_index.h"

TileIndex TileIndex::get_adjacent_index(Direction direction) const
{
    switch (direction.get_type())
    {
    case Direction::Type::up:    return TileIndex{ row - 1,  col };
    case Direction::Type::down:  return TileIndex{ row + 1,  col };
    case Direction::Type::left:  return TileIndex{ row,      col - 1 };
    case Direction::Type::right: return TileIndex{ row,      col + 1 };
    }

    return *this;
}

bool operator==(const TileIndex& a, const TileIndex& b)
{
    return a.row == b.row && a.col == b.col;
}

bool operator!=(const TileIndex& a, const TileIndex& b)
{
    return !(a == b);
}