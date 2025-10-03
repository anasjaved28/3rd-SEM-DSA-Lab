#include <stdio.h>

int main() {
    int arr1[50], arr2[50], mergedArr[100];
    int size1, size2, mergeSize;
    int i, k;

    // --- Input for the first array ---
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // --- Input for the second array ---
    printf("\nEnter the size of the second array: ");
    scanf("%d", &size2);

    printf("Enter the elements of the second array:\n");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // --- Merging the arrays ---
    mergeSize = size1 + size2;

    // Copy elements from the first array to the merged array
    for (i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }

    // Copy elements from the second array to the merged array
    // 'k' starts from size1 to continue where the last element of arr1 was placed.
    for (i = 0, k = size1; k < mergeSize && i < size2; i++, k++) {
        mergedArr[k] = arr2[i];
    }

    // --- Displaying the merged array ---
    printf("\nThe merged array is:\n");
    for (i = 0; i < mergeSize; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    return 0;
}