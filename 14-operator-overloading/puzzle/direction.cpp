#include "direction.h"

Direction Direction::get_random_direction()
{
    Type random{ static_cast<Type>(Random::get(0, Type::max_directions - 1)) };
    return Direction{ random };
}

Direction::Type Direction::get_type() const
{
    return type;
}

Direction Direction::operator-() const
{
    switch (type)
    {
    case up:    return Direction{ down };
    case down:  return Direction{ up };
    case left:  return Direction{ right };
    case right: return Direction{ left };
    }

    assert(0 && "Invalid direction type!");
    return Direction{ up };
}

std::ostream& operator<<(std::ostream& out, const Direction& direction)
{
    switch (direction.get_type())
    {
    case Direction::up:    return (out << "up");
    case Direction::down:  return (out << "down");
    case Direction::left:  return (out << "left");
    case Direction::right: return (out << "right");
    default:               return (out << "unknown direction");
    }
}