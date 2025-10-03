#include <stdio.h>

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n) {
    int i, j;
    int temp;
    int swaps_made; // Optimization flag

    // Outer loop controls the number of passes
    // In each pass, the largest unsorted element bubbles up to its final position
    for (i = 0; i < n - 1; i++) {
        swaps_made = 0; // Reset swap flag for the current pass
        printf("\n--- Pass %d ---\n", i + 1);

        // Inner loop performs comparisons and swaps for the current pass
        // n-1 is the last element, i accounts for already sorted elements at the end
        for (j = 0; j < n - 1 - i; j++) {
            
            // Print elements being compared
            printf("Comparing %d and %d: ", arr[j], arr[j+1]);
            
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps_made = 1; // A swap was made
                printf("SWAP -> [");
                for (int k = 0; k < n; k++) {
                    printf("%d%s", arr[k], (k < n - 1 ? ", " : ""));
                }
                printf("]\n");

            } else {
                printf("NO SWAP\n");
            }
        }
        
        // OPTIMIZATION: If no two elements were swapped by the inner loop,
        // then the array is already sorted, and we can break the outer loop.
        if (swaps_made == 0) {
            printf("\nArray is sorted! Exiting early.\n");
            break;
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
    int arr[] = {6, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Initial Array: ");
    printArray(arr, n);

    // Perform the sort
    bubbleSort(arr, n);

    printf("\nSorted Array: ");
    printArray(arr, n);

    return 0;
}