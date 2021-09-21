#include <iostream>

int main()
{
  int outer{5};

  while (outer > 0)
  {
    int inner{outer};

    while (inner > 1)
    {
      std::cout << inner << ' ';
      --inner;
    }

    std::cout << inner << '\n';
    --outer;
  }

  return 0;
}