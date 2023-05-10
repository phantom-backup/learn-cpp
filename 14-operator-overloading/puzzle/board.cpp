#include "board.h"

#include <algorithm>

constexpr int console_lines{ 25 };
constexpr int randomize_steps{ 10000 };

Board::Board()
{
    for (int i = 0; i < randomize_steps; ++i)
    {
        move_tile(Direction::get_random_direction());
    }
}

bool Board::move_tile(const Direction direction)
{
    TileIndex index_to_move = empty_index.get_adjacent_index(direction);

    if (index_to_move == empty_index || !is_valid_index(index_to_move)) {
        return false;
    }

    swap_tiles(index_to_move, empty_index);
    empty_index = index_to_move;
    return true;
}

bool Board::is_solved() const
{
    for (int i = 0; i < size * size; ++i)
    {
        int target{ (i + 1) % (size * size) };

        if (tiles[i / size][i % size].get_num() != target)
        {
            return false;
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    for (int i{ 0 }; i < console_lines; ++i)
    {
        out << std::endl;
    }

    for (int row{ 0 }; row < Board::size; ++row)
    {
        for (int col{ 0 }; col < Board::size; ++col)
        {
            out << board.tiles[row][col];
        }

        out << std::endl;
    }

    return out;
}

bool Board::is_valid_index(const TileIndex index) const
{
    return index.get_row() >= 0
        && index.get_col() >= 0
        && index.get_row() < size
        && index.get_col() < size;
}

void Board::swap_tiles(const TileIndex a, const TileIndex b)
{
    std::swap(tiles[a.get_row()][a.get_col()], tiles[b.get_row()][b.get_col()]);
}