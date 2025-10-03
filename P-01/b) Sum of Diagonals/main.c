#include <stdio.h>

int main() {
    int N;
    // Read the size of the square matrix
    printf("Enter the Size of Square matrix: ");
    scanf("%d", &N);

    int matrix[100][100];
    int i, j;

    // Read the elements of the matrix
    printf("Enter elements of matrix: ");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    long long sum = 0;

    // Loop through the matrix to find diagonal elements
    for (i = 0; i < N; i++) {
        // Add element from the primary diagonal (top-left to bottom-right)
        sum += matrix[i][i];
        
        // Add element from the secondary diagonal (top-right to bottom-left)
        sum += matrix[i][N - 1 - i];
    }

    // If N is odd, the center element is counted twice, so we subtract it once.
    if (N % 2 == 1) {
        int middle_index = N / 2;
        sum -= matrix[middle_index][middle_index];
    }

    // Print the final sum
    printf("Sum of primary and secondary diagonal element: %lld\n", sum);

    return 0;
}