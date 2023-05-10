#include "user_input.h"

#include <cassert>
#include <iostream>
#include <limits>

static void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static char get_character()
{
    char c{};
    std::cin >> c;
    ignore_line();
    return c;
}

namespace UserInput
{
    Command get_command_from_user()
    {
        char c{};

        while (!is_valid_command(c))
        {
            std::cout << "Enter a command: ";
            c = get_character();
        }

        return static_cast<Command>(c);
    }

    Direction get_direction_from_command(Command command)
    {
        switch (command)
        {
        case Command::slide_up:    return Direction::up;
        case Command::slide_left:  return Direction::left;
        case Command::slide_down:  return Direction::down;
        case Command::slide_right: return Direction::right;
        }

        assert(0 && "Command not associated with a direction!");
        return Direction::up;
    }
}