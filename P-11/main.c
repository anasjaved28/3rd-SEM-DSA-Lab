#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Structure for a Node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for the Graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Queue for BFS
int queue[MAX_VERTICES];
int front = -1;
int rear = -1;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));
    
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Add edge from dest to src for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Check if queue is empty
int isQueueEmpty() {
    return front == -1;
}

// Enqueue operation
void enqueue(int data) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

// Dequeue operation
int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return data;
}

// BFS algorithm using a queue
void BFS(Graph* graph, int startVertex) {
    printf("BFS Traversal starting from vertex %d:\n", startVertex);
    
    // Reset visited array
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
    
    graph->visited[startVertex] = 1;
    enqueue(startVertex);
    
    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS algorithm using recursion
void DFS_recursive(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;
    
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS_recursive(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Main DFS function
void DFS(Graph* graph, int startVertex) {
    printf("DFS Traversal starting from vertex %d:\n", startVertex);
    
    // Reset visited array
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
    
    DFS_recursive(graph, startVertex);
    printf("\n");
}

int main() {
    // Create a graph with 6 vertices (0, 1, 2, 3, 4, 5)
    Graph* graph = createGraph(6);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    BFS(graph, 0); // Start BFS from vertex 0
    
    printf("\n");
    
    DFS(graph, 0); // Start DFS from vertex 0
    
    return 0;
}