#include "board.h"
#include "direction.h"
#include "tile.h"
#include "tile_index.h"
#include "user_input.h"

#include <iostream>

int main()
{
    Board board{};
    std::cout << board << std::endl;

    while (true)
    {
        if (board.is_solved())
        {
            std::cout << "\nYou won!\n\n" << std::endl;
            break;
        }

        UserInput::Command command = UserInput::get_command_from_user();

        if (command == UserInput::Command::quit_game) {
            std::cout << "\n\nBye!\n\n" << std::endl;
            break;
        }
        else
        {

            Direction direction = UserInput::get_direction_from_command(command);
            bool is_move_valid { board.move_tile(-direction) };

            if (is_move_valid)
            {
                std::cout << board << std::endl;
            }
        }
    }

    return 0;
}