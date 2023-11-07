// Lithish is working on a project that involves analyzing the connectivity of various data points represented as vertices in a graph. He needs to perform Depth First Traversal (DFS) on the given graph (connected undirected graph) to explore its vertices and understand the relationships between them.



// Write a program to help Lithish perform DFS on the given graph.

// Input format :
// The first line of input consists of the two integers V and E, separated by a space. V represents the number of vertices, and E represents the number of edges in the graph.

// The next E lines consist of two integers, v and w, separated by a space, indicating an edge between vertex v and vertex w.

// The last line of input consists of the startVertex, representing the starting vertex for DFS traversal.

// Output format :
// The output should print the Depth First Traversal of the graph starting from a specified vertex, following format:

// "Depth First Traversal starting from vertex [vertex]:

// [u1] [u2] [u3]... [un]".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ V ≤ 10

// 0 <= E <= V*(V-1)/2

// 0 <= v, w < V

// 0 ≤ startVertex < V
#include <iostream>
using namespace std;
#define MAX_VERTICES 100

void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adj[v][w] = 1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < V; ++i) {
        if (adj[v][i] && !visited[i]) {
            DFS(adj, visited, V, i);
        }
    }
}

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        addEdge(adj, v, w);
    }

    int startVertex;
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, visited, V, startVertex);

    return 0;
}
