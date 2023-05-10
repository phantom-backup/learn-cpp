#pragma once

#include "random.h"

#include <cassert>
#include <iostream>

class Direction
{
public:
    enum Type
    {
        up,
        down,
        left,
        right,
        max_directions
    };

    Direction(Type type) : type{ type }
    {
    }

    static Direction get_random_direction();
    Type get_type() const;
    Direction operator-() const;

private:
    const Type type;
};

std::ostream& operator<<(std::ostream& out, const Direction& direction);