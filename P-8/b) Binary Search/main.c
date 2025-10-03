#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2; // A safer way to calculate mid to prevent integer overflow

        if (arr[mid] == target) {
            return mid; // Element found, return its index
        }
        if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int key = 23; // The element we want to find

    int result = binarySearch(sortedArray, n, key);

    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}