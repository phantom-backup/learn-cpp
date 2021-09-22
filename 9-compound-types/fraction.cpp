#include <iostream>

struct Fraction
{
  int numerator{};
  int denominator{};
};

Fraction getFraction()
{
  Fraction fraction{};
  std::cout << "Enter the numerator: ";
  std::cin >> fraction.numerator;
  std::cout << "Enter the denominator: ";
  std::cin >> fraction.denominator;
  return fraction;
}

double multiply(Fraction x, Fraction y)
{
  return static_cast<double>(x.numerator * y.numerator) / (x.denominator * y.denominator);
}

int main()
{
  Fraction x{getFraction()};
  Fraction y{getFraction()};

  std::cout << x.numerator << '/' << x.denominator << " times " <<
    y.numerator << '/' << y.denominator << " equals " << multiply(x, y) << '\n';

  return 0;
}