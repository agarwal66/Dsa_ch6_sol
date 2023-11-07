// Raju, a computer analyst, is working on a project that involves examining how different points in a network are connected. He needs to figure out if there's a valid way to get from one point to another based on the network setup. To solve this problem, Raju decided to create a program.



// His job is to develop a program that takes a network described as a set of connections between nodes and checks if there's a way to go from a starting point to an ending point in the network. For this task, he's chosen to use the Depth-First Search (DFS) algorithm.

// Input format :
// The first line of input consists of two integers, n representing the number of nodes in the network and m representing the number of edges, separated by a space.

// The next m lines each contain two integers, u and v, indicating an edge between nodes u and v in the network.

// The last two lines of input consist of two integers, start and end, representing the starting and ending nodes for which Raju wants to find a valid path.

// Output format :
// The output displays one of the following two lines:



// "There is a path from [start] to [end]" if a valid path exists from the starting node to the ending node.

// "There is no path from [start] to [end]" if no valid path exists.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases fall under the following constraints:

// 1 ≤ n ≤ 10, 0 ≤ m ≤ n*(n-1)/2

// 0 ≤ u, v ≤ n, u ≠ v

// 0 ≤ start, end ≤ n, start ≠ end
#include <iostream>

using namespace std;

bool dfs(int adjMatrix[][100], int n, int start, int end, bool visited[]) {
    if (start == end)
        return true;
    
    visited[start] = true;
    
    for (int i = 0; i < n; ++i) {
        if (adjMatrix[start][i] && !visited[i] && dfs(adjMatrix, n, i, end, visited))
            return true;
    }
    
    return false;
}

bool validPath(int n, int edges[][2], int m, int start, int end) {
    int adjMatrix[100][100] = {0};
    
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    
    bool visited[100] = {false};
    
    return dfs(adjMatrix, n, start, end, visited);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int edges[m][2];
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    int start, end;
    cin >> start >> end;
    
    if (validPath(n, edges, m, start, end)) {
        cout << "There is a path from " << start << " to " << end << endl;
    } else {
        cout << "There is no path from " << start << " to " << end << endl;
    }

    return 0;
}