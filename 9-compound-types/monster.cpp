#include <iostream>
#include <string>

enum class MonsterType
{
  ogre,
  dragon,
  orc,
  giant_spider,
  slime
};

std::string getMonsterType(MonsterType monsterType)
{
  switch (monsterType)
  {
    case MonsterType::ogre:
      return "Ogre";
    case MonsterType::dragon:
      return "Dragon";
    case MonsterType::orc:
      return "Orc";
    case MonsterType::giant_spider:
      return "Giant Spider";
    case MonsterType::slime:
      return "Slime";
    default:
      return "???";
  }
}

struct Monster
{
  MonsterType type{};
  std::string name{};
  int health{};
};

void printMonster(Monster monster)
{
  std::cout << "This " << getMonsterType(monster.type) << " is named " <<
    monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
  Monster torg{MonsterType::ogre, "Torg", 145};
  Monster blurp{MonsterType::slime, "Blurp", 23};

  printMonster(torg);
  printMonster(blurp);

  return 0;
}