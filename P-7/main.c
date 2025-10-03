#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int currentSize = 0;

// Function prototypes
int isFull();
int isEmpty();
void enqueue(int data);
int dequeue();
void display();

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Full\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Checks if the queue is full
int isFull() {
    return currentSize == MAX_SIZE;
}

// Checks if the queue is empty
int isEmpty() {
    return currentSize == 0;
}

// Adds an element to the rear of the queue
void enqueue(int data) {
    if (isFull()) {
        printf("Error: Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    currentSize++;
    printf("Enqueued element: %d\n", data);
}

// Removes an element from the front of the queue
int dequeue() {
    if (isEmpty()) {
        printf("Error: Queue is empty. Cannot dequeue.\n");
        return -1; // Sentinel value
    }

    int removed_item = queue[front];
    currentSize--;

    if (currentSize == 0) {
        // Reset indices if the queue becomes empty
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    printf("Dequeued element: %d\n", removed_item);
    return removed_item;
}

// Displays all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int count = 0;
    int i = front;

    while (count < currentSize) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}