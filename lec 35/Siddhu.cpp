// Siddhu works for a logistics company that handles a complex supply chain. This supply chain includes many suppliers, warehouses, and retail stores, all connected through different routes and transportation methods.



// Your job is to assist him in creating a program that utilizes Breadth-First Search (BFS) traversal to improve the supply chain's efficiency. The program will find the best route for delivering products from a supplier to a retail store.

// Input format :
// The first line consists of two integers, V and E, separated by a space, where V represents the number of vertices (locations, suppliers, warehouses, and retail stores), and E represents the number of edges (connections between these locations).

// The next E lines each consist of two integers, u and v, separated by a space, representing an edge between location u and location v.

// Output format :
// The output prints the BFS traversal order of the supply chain, separated by spaces.

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