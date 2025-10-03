// Implementation of Selection Sort:

// Rearrange the following code:
//     • SelectionSort(A)
//     • for i = 0 to length(A) - 2 do
//     • minIndex = i
//     • for j = i + 1 to length(A) - 1 do
//     • if A[j] < A[minIndex] then
//     • swap A[i] with A[minIndex]
//     • end if
//     • end for
//     • if minIndex != i then
//     • minIndex = j
//     • end if
//     • end for
//     • end SelectionSort
// Task:
//     • Given the Selection Sort pseudocode, rearrange it correctly.


                                                                                                  


// selectionSort(A)
//   for i = 0 to length(A) - 2 do
//     minIndex = i
//     for j = i + 1 to length(A) - 1 do
//       if A[j] < A[minIndex] then
//         minIndex = j
//       end if
//     end for
//     if minIndex != i then
//       swap A[i] with A[minIndex]
//     end if
//   end for
// end SelectionSort



                                                                                                   

// Optional Code (Ask Sir if he wants code then write)
#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    int temp;

    // Outer loop to iterate through the array
    for (i = 0; i < n - 1; i++) {
        // Assume the first element of the unsorted part is the minimum
        min_idx = i;

        // Inner loop to find the minimum element in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        // We only swap if the minimum element is not already at its correct position
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Function to print the elements of the array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size - 1 ? ", " : ""));
    }
    printf("]\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}