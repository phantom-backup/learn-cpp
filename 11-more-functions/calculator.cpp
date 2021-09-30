#include <iostream>
#include <functional>
#include <limits>
#include <string>

template <typename T>
T getInput(const std::string& prompt, std::function<bool(T)> validateFcn = nullptr)
{
  while (true)
  {
    std::cout << prompt;
    T input{};
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input.\n";
    }
    else if (!validateFcn || (validateFcn && validateFcn(input)))
    {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return input;
    }
    else
    {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input.\n";
    }
  }
}

bool validateOperation(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  return x - y;
}

int multiply(int x, int y)
{
  return x * y;
}

int divide(int x, int y)
{
  return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char operation)
{
  switch (operation)
  {
    case '+': return add;
    case '-': return subtract;
    case '*': return multiply;
    case '/': return divide;
  }

  std::cout << "Invalid operation: " << operation << '\n';
  return nullptr;
}

int main()
{
  int x{getInput<int>("Enter an integer: ")};
  int y{getInput<int>("Enter another integer: ")};
  char operation{getInput<char>("Enter an operation (+, -, *, or /): ", validateOperation)};

  auto arithmeticFunction{getArithmeticFunction(operation)};

  if (arithmeticFunction)
  {
    std::cout << x << ' ' << operation << ' ' << y << " = " << arithmeticFunction(x, y) << '\n';
  }

  return 0;
}