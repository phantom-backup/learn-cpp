#include <cmath>
#include <iostream>

class Fraction
{
private:
    int numerator{0};
    int denominator{ 1 };

    int gcd(int a, int b)
    {
        return (b == 0) ? std::abs(a) : gcd(b, a % b);
    }

public:
    Fraction() = default;

    Fraction(int numerator, int denominator = 1) : numerator{ numerator }, denominator{ denominator }
    {
        reduce();
    }

    void reduce()
    {
        int g = gcd(numerator, denominator);

        if (g != 0)
        {
            numerator /= g;
            denominator /= g;
        }
    }

    Fraction operator*(const Fraction& rhs)
    {
        return Fraction{ this->numerator * rhs.numerator, this->denominator * rhs.denominator };
    }

    bool operator==(const Fraction& rhs) {
        return this->numerator == rhs.numerator && this->denominator == rhs.denominator;
    }

    bool operator!=(const Fraction& rhs) {
        return !this->operator==(rhs);
    }

    bool operator<(const Fraction& rhs) {
        return this->numerator / this->denominator < rhs.numerator / rhs.denominator;
    }

    bool operator>(const Fraction& rhs) {
        return this->numerator / this->denominator > rhs.numerator / rhs.denominator;
    }

    bool operator<=(const Fraction& rhs) {
        return !this->operator>(rhs);
    }

    bool operator>=(const Fraction& rhs) {
        return !this->operator<(rhs);
    }

    friend std::istream& operator>>(std::istream& in, Fraction& fraction)
    {
        std::string temp;
        in >> temp;
        size_t slash = temp.find('/');
        fraction.numerator = std::stoi(temp.substr(0, slash));
        fraction.denominator = std::stoi(temp.substr(slash + 1, temp.size()));
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
    {
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }

    void print() const
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main()
{
    Fraction f1{ 3, 2 };
    Fraction f2{ 5, 8 };

    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
    return 0;
}
