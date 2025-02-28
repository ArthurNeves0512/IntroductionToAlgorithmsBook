#include "iostream"
#include <charconv>
#include <iterator>
#include <ostream>
#include <sys/types.h>
// using function pointer
void insertionSort(int[], int, void (*)(int[], int));

void descendingInsertionSort(int[], int);
void descendingInsertionSort(int array[], int size) {
  for (int iterator = 1; iterator < size; iterator++) {
    int value_to_sort = array[iterator];
    int previus_value = array[iterator - 1];
    int previus_indice = iterator - 1;
    while (previus_indice >= 0 && value_to_sort > array[previus_indice]) {
      previus_value = array[previus_indice];
      array[previus_indice + 1] = previus_value;
      previus_indice--;
    }
    array[previus_indice + 1] = value_to_sort;
  }
}

void ascendingInsertionSort(int[], int);
void ascendingInsertionSort(int array[], int size) {
  for (int iterator = 1; iterator < size; iterator++) {
    int value_to_sort = array[iterator];
    int previus_indice = iterator - 1;
    int previus_value = array[previus_indice];
    while (previus_indice >= 0 && array[previus_indice] > value_to_sort) {
      previus_value = array[previus_indice];
      array[previus_indice + 1] = previus_value;
      previus_indice--;
    }
    array[previus_indice + 1] = value_to_sort;
  }
}

void insertionSort(int vetor[], int size, void (*sortFunc)(int[], int)) {
  (*sortFunc)(vetor, size);
}

int main(int argc, char *argv[]) {

  int vetor[] = {9, 8, 7, 6, 5, 4, 4, 4, 9, 3, 2};

  int size = std::size(vetor);

  std::cout << "Original Array" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << vetor[i] << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Ascending sort result" << std::endl;
  insertionSort(vetor, size, ascendingInsertionSort);
  for (int i = 0; i < size; i++) {
    std::cout << vetor[i] << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Descending sort result" << std::endl;
  insertionSort(vetor, size, descendingInsertionSort);
  for (int i = 0; i < size; i++) {
    std::cout << vetor[i] << std::endl;
  }
  return 0;
}
