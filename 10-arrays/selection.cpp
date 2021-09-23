#include <iostream>
#include <utility>

void printArray(int array[], int size)
{
  for (int i{0}; i < size; ++i)
  {
    std::cout << array[i] << (i != size - 1 ? ", " : "\n");
  }
}

void selectionSort(int array[], int size, bool ascending = true)
{
  for (int start{0}; start < size - 1; ++start)
  {
    int minIndex{start};

    for (int i{start}; i < size; ++i)
    {
      if ((ascending && array[i] < array[minIndex]) ||
          (!ascending && array[i] > array[minIndex]))
        minIndex = i;
    }

    std::swap(array[start], array[minIndex]);
    printArray(array, size);
  }
}

int main()
{
  int array[]{30, 60, 20, 50, 40, 10};
  int size = sizeof(array) / sizeof(int);

  printArray(array, size);
  selectionSort(array, size, true);

  return 0;
}