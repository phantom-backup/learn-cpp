#pragma once

#include "direction.h"

namespace UserInput
{
    enum class Command
    {
        slide_up = ',',
        slide_left = 'a',
        slide_down = 'o',
        slide_right = 'e',
        quit_game = 'q'
    };

    static bool is_valid_command(char c)
    {
        return c == ','
            || c == 'a'
            || c == 'o'
            || c == 'e'
            || c == 'q';
    }

    Command get_command_from_user();
    Direction get_direction_from_command(Command command);
}