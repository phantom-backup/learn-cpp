#pragma once

#include "direction.h"
#include "tile.h"
#include "tile_index.h"

#include <iostream>

class Board
{
public:
    Board();

    bool move_tile(const Direction direction);
    bool is_solved() const;

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

private:
    static constexpr int size{ 4 };

    Tile tiles[size][size]{
        {1,  2,   3,  4},
        {5,  6,   7,  8},
        {9,  10, 11, 12},
        {13, 14, 15,  0}
    };

    TileIndex empty_index{ size - 1, size - 1 };

    bool is_valid_index(const TileIndex index) const;
    void swap_tiles(const TileIndex a, const TileIndex b);
};