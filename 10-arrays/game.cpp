#include <array>
#include <iostream>
#include <numeric>

enum ItemType
{
  health_potion,
  torch,
  arrow,
  max_items
};

int countTotalItems(const std::array<int, max_items>& items)
{
  return std::accumulate(items.begin(), items.end(), 0);
}

int main()
{
  std::array<int, 3> items{2, 5, 10};

  std::cout << "You have " << countTotalItems(items) << " items.\n";
  std::cout << "You have " << items.at(torch) << " torches.\n";

  return 0;
}