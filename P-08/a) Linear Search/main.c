#include <stdio.h>

int main() {
    int arr[] = {4, 1, 6, 8, 77, 9, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 77;
    int found = 0; // Flag to check if the target is found

    for (int i = 0; i < n; i++) {
        // Compare the current element with the target
        if (arr[i] == target) {
            found = 1; // Set the flag to true
            break;     // Exit the loop once the target is found
        }
    }

    if (found) {
        printf("Yes\n");
    }

    return 0;
}