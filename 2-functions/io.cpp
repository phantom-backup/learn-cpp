#include "io.h"
#include <iostream>

int readNumber()
{
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;
  return input;
}

void writeAnswer(int sum)
{
  std::cout << "The sum is " << sum << ".\n";
}