#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
  std::string name{};
  int grade{};
};

bool compareStudents(const Student &a, const Student &b)
{
  return (a.grade > b.grade);
}

void printStudent(const Student &student)
{
  std::cout << student.name << " got a grade of " << student.grade << ".\n";
}

int main()
{
  std::cout << "How many students do you want to enter? ";
  int numStudents{};
  std::cin >> numStudents;

  std::vector<Student> students(numStudents);

  for (Student &student : students)
  {
    std::cin >> student.name;
    std::cin >> student.grade;
  }

  std::sort(students.begin(), students.end(), compareStudents);

  std::for_each(students.begin(), students.end(), printStudent);

  return 0;
}