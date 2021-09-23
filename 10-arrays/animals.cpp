#include <iostream>

namespace Animals
{
  enum
  {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_animal_species
  };
}

int numberOfLegs[Animals::max_animal_species]{2, 4, 4, 4, 2, 0};

int main()
{
  std::cout << "Elephants have " << numberOfLegs[Animals::elephant] << " legs.\n";
}