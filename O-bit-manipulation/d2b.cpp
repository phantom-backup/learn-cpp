#include <cmath>
#include <iostream>

int main()
{
  constexpr int maxExponent{15};
  const int maxPowerOfTwo{static_cast<int>(pow(2, maxExponent + 1) - 1)};

  std::cout << "Enter an integer from 0 to " << maxPowerOfTwo << ": ";
  int x{};
  std::cin >> x;

  if (x < 0 || x > maxPowerOfTwo)
    return 0;

  for (int e{maxExponent}; e >= 0; --e)
  {
    double b{pow(2, e)};
    std::cout << (x >= b);

    if (x >= b)
      x -= pow(2, e);

    if (e % 4 == 0 && e != 0)
      std::cout << ' ';
  }

  std::cout << '\n';

  return 0;
}