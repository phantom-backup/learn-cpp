/*
  drop.cpp
  
  Simulates a ball being dropped from a tower. Requests the height of the tower
  in meters from the user and prints the height of the ball at each second until
  it hits the ground.
*/

#include <iostream>

double getHeight()
{
  std::cout << "Enter the height of the tower in meters: ";
  double input{};
  std::cin >> input;
  return input;
}

double distanceFallen(double seconds)
{
  constexpr double gravity { 9.8 }; // m/s^2
  return gravity * seconds * seconds / 2.0;
}

int main()
{
  const double initialHeight { getHeight() };
  double height { initialHeight };
  int seconds { 0 };

  while (height > 0)
  {
    std::cout << "At " << seconds << " seconds, the ball is at height: " <<
      height << " meters\n";
    
    seconds++;
    height = initialHeight - distanceFallen(seconds);
  }

  std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";

  return 0;
}