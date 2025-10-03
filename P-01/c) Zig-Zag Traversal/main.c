#include <stdio.h>

int main() {
    // Declare variables for rows (N) and columns (M)
    int N, M;

    // Read the dimensions of the matrix
    printf("Enter Size of Row and Column of Matrix: ");
    scanf("%d %d", &N, &M);

    // Declare a 2D array with the given dimensions
    int matrix[N][M];

    // Read the elements of the matrix from the user
    printf("Enter Elements of %dx%d matrix: ",N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // --- Zig-Zag Traversal Logic ---
    // Iterate through each row of the matrix
    for (int i = 0; i < N; i++) {
        // Check if the current row index is even (0, 2, 4, ...)
        if (i % 2 == 0) {
            // For even rows, print from left to right
            for (int j = 0; j < M; j++) {
                printf("%d ", matrix[i][j]);
            }
        } else {
            // For odd rows (1, 3, 5, ...), print from right to left
            for (int j = M - 1; j >= 0; j--) {
                printf("%d ", matrix[i][j]);
            }
        }
    }

    printf("\n"); // Print a newline at the end

    return 0;
}