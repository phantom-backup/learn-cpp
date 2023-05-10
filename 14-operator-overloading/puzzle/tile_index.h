#pragma once

#include "direction.h"

class TileIndex
{
private:
    int row{};
    int col{};

public:
    TileIndex(int row = 0, int col = 0) : row{row}, col{col}
    {
    }

    int get_row() const { return row; }
    int get_col() const { return col; }
    
    TileIndex get_adjacent_index(Direction direction) const;

    friend bool operator==(const TileIndex& a, const TileIndex& b);
    friend bool operator!=(const TileIndex& a, const TileIndex& b);
};