#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w; // u = source, v = destination, w = weight
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 2: Check for negative-weight cycles
    bool negativeCycle = false;
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
        cout << "Graph contains a negative weight cycle!" << endl;
    else {
        cout << "\nVertex\tDistance from Source\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                cout << i << "\t\t" << "INF" << endl;
            else
                cout << i << "\t\t" << dist[i] << endl;
        }
    }

    return 0;
}
