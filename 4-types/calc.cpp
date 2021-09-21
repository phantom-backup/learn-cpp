#include <iostream>

double getDouble()
{
  std::cout << "Enter a double value: ";
  double input{};
  std::cin >> input;
  return input;
}

char getSymbol()
{
  std::cout << "Enter one of the following: +, -, *, or /: ";
  char input{};
  std::cin >> input;
  return input;
}

void printAnswer(double x, double y, char symbol)
{
  if (symbol == '+')
      std::cout << x << " + " << y << " is " << x + y << '\n';
  else if (symbol == '-')
      std::cout << x << " - " << y << " is " << x - y << '\n';
  else if (symbol == '*')
      std::cout << x << " * " << y << " is " << x * y << '\n';
  else if (symbol == '/')
      std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
  double x { getDouble() };
  double y { getDouble() };
  char symbol { getSymbol() };

  printAnswer(x, y, symbol);

  return 0;
}