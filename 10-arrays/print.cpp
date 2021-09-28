#include <iostream>

void printString(const char* string)
{
  while (*string != '\0')
  {
    std::cout << *string;
    ++string;
  }
}

int main()
{
  printString("Hello, world!");

  std::cout << '\n';

  return 0;
}