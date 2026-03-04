#include <iostream>

void printArr(int *arr, size_t size) {
  std::cout << arr[0];
  for (size_t i = 1; i < size; ++i) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

// void siftElement(int *arr, size_t size, size_t index) {
//   while (true) {
//     size_t l = 2 * index + 1;
//     if (l >= size)
//       break;
//     size_t r = l + 1;
//     size_t m = l;
//     if (r < size && arr[r] < arr[l])
//       m = r;
//     if (arr[index] <= arr[m])
//       break;
//     std::swap(arr[index], arr[m]);
//     index = m;
//   }
// }

int *heapSort(int *arr, size_t size) {
  for (int i = size / 2 - 1; i >= 0; --i) {
    int index = i;
    while (true) {
      size_t l = 2 * index + 1;
      if (l >= size) // size > l ==> size - l < 0
        break;
      size_t r = l + 1;
      size_t m = l;
      if (r < size) { // мы хотим r - size >= 0 чтобы скипнуть тело цикла 
        if (*(arr + r) < *(arr + l)) { // мы хотим r8- ra >=0 
          m = r;
        }
      }
      if (*(arr + index) <= *(arr + m))
        break;
      std::swap(*(arr + index), *(arr + m));
      index = m;
    }
    
  }
  for (int i = size - 1; i >= 0; --i) {
    std::swap(*(arr + i), *(arr));
    int index = 0;
    while (true) {
      size_t l = 2 * index + 1;
      if (l >= i)
        break;
      size_t r = l + 1;
      size_t m = l;
      if (r < i)
      {
          if (*(arr + r) < *(arr + l))
          {
              m = r;
          }
      }

      if (arr[index] <= arr[m])
        break;
      std::swap(arr[index], arr[m]);
      index = m;
    }
  }
  return arr;
}

int main() {
  size_t size = 6;
  int arr[6] = {24, 31, 15, 20, 52, 6};
  printArr(arr, size);
  int *sorted_arr = heapSort(arr, size);
  printArr(sorted_arr, size);
}
