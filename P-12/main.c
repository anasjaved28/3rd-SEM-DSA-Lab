#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. InOrder Traversal\n");
        printf("3. PreOrder Traversal\n");
        printf("4. PostOrder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("\nInOrder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("\nPreOrder Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostOrder Traversal: ");
                postOrder(root);
                printf("\n");
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

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Recursively traverse the tree to find the correct position
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the (unchanged) node pointer
    return root;
}

// In-order traversal (Left -> Root -> Right)
// Prints elements in sorted order
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Pre-order traversal (Root -> Left -> Right)
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal (Left -> Right -> Root)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}