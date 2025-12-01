#include <iostream>
#include <climits>
using namespace std;

#define V 5  // number of vertices

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Function to print the shortest distance array
void printSolution(int dist[]) {
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

// Dijkstra’s Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];        // Output array: dist[i] holds shortest distance from src to i
    bool visited[V];    // visited[i] = true if vertex i is processed

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance to the source vertex is 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        // Update dist[v] only if:
        // 1) v is not visited
        // 2) there is an edge from u to v
        // 3) total weight of path from src to v through u is smaller than current dist[v]
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the final result
    printSolution(dist);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
