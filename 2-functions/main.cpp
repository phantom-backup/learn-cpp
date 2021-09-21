#include <iostream>

using namespace std;

int readNumber();

int main()
{
  int x{ readNumber() };
  int y{ readNumber() };

  cout << x << " + " << y << " is " << x + y << "\n";
  return 0;
}