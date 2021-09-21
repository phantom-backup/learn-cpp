#include <iostream>
using namespace std;

int doubleNumber(int x)
{
  return x * 2;
}

int main()
{
  cout << "Enter an integer: ";
  int x{};
  cin >> x;

  cout << x << " doubled is " << doubleNumber(x) << ".\n";

  return 0;
}