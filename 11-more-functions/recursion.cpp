#include <iostream>
#include <vector>

int factorial(int x)
{
  if (x <= 0)
    return 1;

  static std::vector<int> results{1, 1};

  if (x >= static_cast<int>(results.size()))
  {
    results.push_back(factorial(x - 1) * x);
  }

  return results[x];
}

int digitSum(int x)
{
  if (x < 0)
    x = -x;

  if (x < 10)
    return x;
  else
    return digitSum(x / 10) + x % 10;
}

void printDtob(unsigned int x)
{
  if (x == 0)
    return;
    
  printDtob(x / 2);

  std::cout << x % 2;
}

int main()
{
  std::cout << "Factorial: \n";
  for (int i = 1; i <= 7; ++i)
    std::cout << factorial(i) << '\n';
  
  std::cout << "\nDigit Sum: \n";
  std::cout << "357 -> " << digitSum(357) << '\n';
  std::cout << "93427 -> " << digitSum(93427) << '\n';
  
  std::cout << "\nEnter an integer to convert to binary: ";
  int x{};
  std::cin >> x;
  printDtob(static_cast<unsigned int>(x));
  std::cout << '\n';

  return 0;
}