#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define max size large enough for N=10 and others

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function prototypes for queue operations
int isEmpty();
void enqueue(int data);
int dequeue();
void printPattern(int N);
void displayRemaining();

int main() {
    int N;
    printf("Enter the value for N (e.g., 10): ");
    
    // Safety check to ensure N is within reasonable bounds
    if (scanf("%d", &N) != 1 || N <= 0 || N > MAX_SIZE) {
        printf("Invalid input or N is too large. Setting N to 10.\n");
        N = 10;
    }
    
    printf("\n--- Pattern for N=%d ---\n", N);
    printPattern(N);
    
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Add an element to the rear of the queue
void enqueue(int data) {
    // Note: We skip the isFull check assuming MAX_SIZE is large enough for the task's N
    if (rear == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

// Remove and return an element from the front of the queue
int dequeue() {
    if (isEmpty()) {
        return -1;
    }
    int data = queue[front];
    
    if (front == rear) {
        // Last element removed, reset queue
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return data;
}

// Core logic to implement the pattern
void printPattern(int N) {
    int i;
    
    printf("Printed and Enqueued elements:\n");
    
    for (i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            // Odd number: Print it
            printf("Printed: %d\n", i);
        } else {
            // Even number: Enqueue it
            enqueue(i);
            printf("Enqueued: %d\n", i);
        }
    }
    
    // --- Dequeue Remaining Elements ---
    printf("\nDequeuing remaining elements:\n");
    displayRemaining();
}

// Displays all remaining elements in the queue
void displayRemaining() {
    int dequeued_item;
    
    if (isEmpty()) {
        printf("Queue is empty. No remaining elements.\n");
        return;
    }
    
    // Dequeue and print all items until the queue is empty
    while (!isEmpty()) {
        dequeued_item = dequeue();
        printf("Dequeued: %d\n", dequeued_item);
    }
}