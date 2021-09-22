#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

struct AdvertStats
{
  int adsShown{};
  float clickPercentage{};
  long double revenuePerClick{};
};

void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getInput(const std::string& prompt)
{
  while (true)
  {
    std::cout << prompt;
    T input{};
    std::cin >> input;

    if (std::cin.fail())
    {
      std::cin.clear();
      ignoreLine();
      std::cout << "Invalid input. Please try again.\n";
    }
    else
    {
      ignoreLine();
      return input;
    }
  }
}

void printStats(AdvertStats stats)
{
  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  std::cout << "Ads shown: " << stats.adsShown << '\n';
  std::cout << "Click percentage: " << stats.clickPercentage << "%\n";
  std::cout << "Revenue per click: $" << stats.revenuePerClick << '\n';

  long double total{stats.adsShown * stats.clickPercentage / 100 * stats.revenuePerClick};
  std::cout << "Total revenue: $" << total << '\n';
}

int main()
{
  AdvertStats stats{};
  stats.adsShown = getInput<int>("Enter the number of ads shown to users: ");
  stats.clickPercentage = getInput<float>("Enter the percentage of ads clicked on: ");
  stats.revenuePerClick = getInput<long double>("Enter the average revenue per ad click: ");

  printStats(stats);

  return 0;
}