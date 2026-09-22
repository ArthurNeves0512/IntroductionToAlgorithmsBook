#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>

int *mergeSort(int[]);

int *mergeSort(int vetor[]) {
  int arraySize = sizeof(vetor);
  std::cout << arraySize;
  std::cout << sizeof(int);
  return vetor;
}

int main(int argc, char *argv[]) {

  int a[4] = {1, 2, 3, 4};
  int *ptr = a;
  std::cout << sizeof(ptr) << std::endl;
  mergeSort(a);
  return 0;
}
