#include <iostream>

void printArr(int *arr, size_t n)
{
  for (size_t i = 0; i < n; ++i)
  {
    if (i)
      std::cout << " ";
    std::cout << arr[i];
  }
  std::cout << "\n";
}

size_t minFrom3(int *arr, size_t i, size_t fch, size_t sch)
{
  if (arr[i] < arr[fch] && arr[i] < arr[sch])
  {
    return i;
  }
  else if (arr[fch] < arr[i] && arr[fch] < arr[sch])
  {
    return fch;
  }
  else
  {
    return sch;
  }
}

void balancePyramid(int *arr, int n, size_t elem_i)
{
  for (int j = elem_i; j <= n / 2 - 1;)
  {
    size_t minJ = j;
    size_t firstChild = j * 2 + 1;
    size_t secondChild = j * 2 + 2;
    if (secondChild < n)
    {
      minJ = minFrom3(arr, minJ, firstChild, secondChild);
    }
    else if (arr[j] > arr[firstChild])
    {
      minJ = firstChild;
    }

    std::swap(arr[j], arr[minJ]);
    j = (minJ == j) ? n : minJ;
  }
}

void buildPyramid(int *arr, size_t n)
{
  for (int i = (n / 2 - 1); i >= 0; --i)
  {
    balancePyramid(arr, n, i);
  }
}

void pyramidSort(int *arr, size_t n)
{
  for (int i = n - 1; i >= 0; --i)
  {
    std::swap(arr[i], arr[0]);
    balancePyramid(arr, i, 0);
  }
}

int main()
{
  const size_t size = 6;
  int arr[] = {24, 31, 15, 20, 52, 6};

  buildPyramid(arr, size);

  pyramidSort(arr, size);
  printArr(arr, size);
}
