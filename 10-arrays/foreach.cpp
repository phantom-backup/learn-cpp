#include <iostream>
#include <string>
#include <string_view>

int main()
{
  const std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily",
                            "Fred", "Greg", "Holly"};

  std::cout << "Enter a name: ";
  std::string input{};
  std::cin >> input;

  bool found{false};

  for (const auto name : names)
  {
    if (name == input)
    {
      found = true;
      break;
    }
  }

  std::cout << input << " was " << (found ? "" : "not ") << "found.\n";

  return 0;
}