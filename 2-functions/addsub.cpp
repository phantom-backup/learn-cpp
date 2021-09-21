#include <iostream>

int getInput()
{
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;

  return input;
}

int main()
{
  int x { getInput() };
  int y { getInput() };

  std::cout << x << " + " << y << " is " << x + y << ".\n";
  std::cout << x << " - " << y << " is " << x - y << ".\n";

  return 0;
}