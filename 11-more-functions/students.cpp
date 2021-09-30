#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Student
{
  std::string name{};
  int points{};
};

int main()
{
  std::array<Student, 8> array{
      {{"Albert", 3},
       {"Ben", 5},
       {"Christine", 2},
       {"Dan", 8},
       {"Enchilada", 4},
       {"Francis", 1},
       {"Greg", 3},
       {"Hagrid", 5}}};

  const auto sortByPoints{
    [](const auto& a, const auto& b)
    {
      return (a.points < b.points);
    }
  };
  
  const auto bestStudent{std::max_element(array.begin(), array.end(), sortByPoints)};

  std::cout << bestStudent->name << " is the best student\n";

  return 0;
}