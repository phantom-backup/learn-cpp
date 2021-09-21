#include <iostream>

int calculate(int x, int y, char op)
{
  switch (op)
  {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
    case '%':
      return x % y;
    default:
      std::cerr << "Error: Invalid operator\n";
      return 0;
  }
}

int main()
{
  std::cout << "Enter an integer: ";
  int x{};
  std::cin >> x;

  std::cout << "Enter another integer: ";
  int y{};
  std::cin >> y;

  std::cout << "Enter an operator (+, -, *, /, or %): ";
  char op{};
  std::cin >> std::ws >> op;

  int answer{calculate(x, y, op)};

  std::cout << "Answer: " << answer << '\n';

  return 0;
}