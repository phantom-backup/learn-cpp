#include "random.h"

#include <iostream>
#include <string>

class Monster
{
public:
    enum Type
    {
        DRAGON,
        GOBLIN,
        OGRE,
        ORC,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES
    };

    Monster(Type type, const std::string &name, const std::string &roar, int hitpoints)
        : type{type}, name{name}, roar{roar}, hitpoints{hitpoints}
    {
    }

    void print() const
    {
        std::cout << name << " the " << typeStrings[type] << " has " << hitpoints
                  << " hitpoints and says " << roar << std::endl;
    }

private:
    Type type{};
    std::string name{};
    std::string roar{};
    int hitpoints{};
    const std::string typeStrings[MAX_MONSTER_TYPES]{
        "dragon",
        "goblin",
        "ogre",
        "orc",
        "skeleton",
        "troll",
        "vampire",
        "zombie"};
};

namespace MonsterGenerator
{
    static const std::string names[] {
        "Bones",
        "Krog",
        "Ugluk",
        "Morbius",
        "Count Dooku",
        "Shrek"
    };

    static const std::string roars[] {
        "*rattle*",
        "\"Lok'tar ogar!\"",
        "\"Time is money, friend.\"",
        "\"Magnets, how do they work?\"",
        "\"Get out of my swamp!\"",
        "\"I am not Count Chocula\""
    };

    Monster generate()
    {
        Monster::Type type = static_cast<Monster::Type>(Random::get(0, Monster::Type::MAX_MONSTER_TYPES - 1));
        std::string name = names[Random::get(0, 5)];
        std::string roar = roars[Random::get(0, 5)];
        int hitpoints = Random::get(1, 100);

        return Monster{type, name, roar, hitpoints};
    }
}

int main()
{
    Monster m{MonsterGenerator::generate()};
    m.print();

    return 0;
}
