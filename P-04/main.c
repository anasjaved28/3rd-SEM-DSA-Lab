#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Defines the maximum capacity of the stack

int stack[MAX_SIZE];
int top = -1; // Initially, the stack is empty

// Function prototypes  
int isFull();
int isEmpty();
void push(int data);
int pop();
int peek();
void display();

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Stack Operations (Array Implementation) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (view top element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("The top element is: %d\n", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Checks if the stack is full
int isFull() {
    if (top == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

// Checks if the stack is empty
int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

// Pushes a new element onto the stack
void push(int data) {
    if (isFull()) {
        printf("Error: Stack Overflow! Cannot push element.\n");
    } else {
        top++;
        stack[top] = data;
        printf("Pushed element %d onto the stack.\n", data);
    }
}

// Pops the top element from the stack
int pop() {
    int data;
    if (isEmpty()) {
        printf("Error: Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    } else {
        data = stack[top];
        top--;
        printf("Popped element %d from the stack.\n", data);
        return data;
    }
}

// Returns the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("The stack is empty.\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Displays all elements in the stack from top to bottom
void display() {
    if (isEmpty()) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements (from top):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}