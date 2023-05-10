#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> map;

public:
    char& operator[](const std::string& name);
};

char& GradeMap::operator[](const std::string& name)
{
    auto isSameName = [&](const auto& student)
    {
        return student.name == name;
    };

    auto iter = std::find_if(map.begin(), map.end(), isSameName);

    if (iter != map.end())
    {
        return iter->grade;
    }

    map.push_back({ name });
    return map.back().grade;
}

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}