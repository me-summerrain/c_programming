#include <stdio.h>

// Function to swap elements
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // pivot element
  int i = (low - 1); // index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // Check if current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]); // put pivot at its final place
  return (i + 1);
}

/* Recursive Quick Sort function */
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[p] is now at right place
    int pi = partition(arr, low, high);

    // Recursively sort elements before and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: \n");
  printArray(arr, n);

  quickSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
