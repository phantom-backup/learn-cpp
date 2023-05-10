#include <iostream>
#include <string>

class MyString
{
private:
    std::string s{};

public:
    MyString(const std::string& s)
    {
        this->s = s;
    }

    MyString operator()(int start, int length)
    {
        return s.substr(start, length);
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& myString)
    {
        out << myString.s;
        return out;
    }
};

int main()
{
    MyString s{ "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}