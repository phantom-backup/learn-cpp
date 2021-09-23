#include <iostream>
#include <utility>

void printArray(int array[], int size)
{
  for (int i{0}; i < size; ++i)
  {
    std::cout << array[i] << (i != size - 1 ? ", " : "\n");
  }
}

void bubbleSort(int array[], int size, bool ascending = true)
{
  for (int end{size - 1}; end > 0; --end)
  {
    bool isSorted{true};

    for (int i{0}; i < end; ++i)
    {
      if ((ascending && array[i] > array[i + 1]) ||
          (!ascending && array[i] < array[i + 1]))
      {
        std::swap(array[i], array[i + 1]);
        isSorted = false;
      }
    }

    if (isSorted && end != 1)
    {
      std::cout << "Early termination on iteration " << size - end << '\n';
      break;
    }
  }
}

int main()
{
  int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
  int size = sizeof(array) / sizeof(int);

  bubbleSort(array, size, true);
  printArray(array, size);

  return 0;
}