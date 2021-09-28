#include <iostream>

void swapInts(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int x{1};
  int y{2};

  swapInts(x, y);

  std::cout << "x is " << x << ", y is " << y << '\n';

  return 0;
}