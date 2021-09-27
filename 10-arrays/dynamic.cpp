#include <algorithm>
#include <iostream>
#include <string>

// Ask the user how many names they wish to enter
int getNumberOfNames()
{
  std::cout << "How many names would you like to enter? ";
  int numberOfNames{};
  std::cin >> numberOfNames;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return numberOfNames;
}

// Ask the user to enter each name
void getNames(std::string* names, int numberOfNames)
{
  for (int i{0}; i < numberOfNames; ++i)
  {
    std::cout << "Enter name #" << i + 1 << ": ";
    std::getline(std::cin, names[i]);
  }
}

// Print the sorted list
void printNames(std::string* names, int numberOfNames)
{
  std::cout << "\nHere is your sorted list:\n";

  for (int i{0}; i < numberOfNames; ++i)
  {
    std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
  }
}

int main()
{
  int numberOfNames{getNumberOfNames()};

  // Dynamically allocate a std::string array
  auto* names{new std::string[numberOfNames]{}};

  getNames(names, numberOfNames);

  // Sort the names
  std::sort(names, names + numberOfNames);

  printNames(names, numberOfNames);

  return 0;
}