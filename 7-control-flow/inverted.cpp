#include <iostream>

int main()
{
  constexpr int max{5};
  int outer{1};

  while (outer <= max)
  {
    int inner{max};

    while (inner > 1)
    {
      if (inner > outer)
      {
        std::cout << "  ";
      }
      else
      {
        std::cout << inner << ' ';
      }

      --inner;
    }

    std::cout << "1\n";
    ++outer;
  }

  return 0;
}