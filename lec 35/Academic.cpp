
// In an academic institution, courses are organized such that some courses are prerequisites for others. The course curriculum can be represented as a graph, where each course is a node and prerequisites between courses are edges.



// Your task is to implement a program that uses Breadth-First Search (BFS) traversal to discover and map these dependencies, starting with a specified course.

// Input format :
// The first line of input consists of two space-separated integers, V and E, representing the total number of courses and prerequisites, respectively.

// The next lines of input consists of two space-separated integers, Details about each prerequisite are represented by two integers u and v, where u is a prerequisite for course v.

// Output format :
// The output should display the discovered courses in the order they were visited during the BFS traversal, separated by spaces. This provides a map of the course dependencies, showing which courses are prerequisites for others.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= V <= 10

// 0 <= E <= V*(V-1)/2

// 0 <= u, v < V
#include <iostream>
using namespace std;

#define MAX_V 100

void enqueue(int* queue, int& rear, int vertex) {
    queue[++rear] = vertex;
}

int dequeue(int* queue, int& front) {
    return queue[++front];
}

void bfsOfGraph(int V, int adjList[MAX_V][MAX_V]) {
    int visited[MAX_V] = {0};
    int queue[MAX_V];
    int front = 0, rear = 0;

    int startVertex = 0;
    enqueue(queue, rear, startVertex);
    visited[startVertex] = 1;

    while (front < rear) {
        int currVertex = dequeue(queue, front);

        cout << currVertex << " ";

        for (int i = 0; i < V; ++i) {
            if (adjList[currVertex][i] == 1 && visited[i] == 0) {
                enqueue(queue, rear, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    int adjList[MAX_V][MAX_V] = {0};

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u][v] = 1;
    }

    bfsOfGraph(V, adjList);

    return 0;
}