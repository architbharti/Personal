#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};
class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }    }    }
};

// Kruskal’s Algorithm
void kruskalMST(vector<Edge>& edges, int V) {

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) { return a.weight < b.weight; });

    UnionFind uf(V);
    vector<Edge> result;
    int totalWeight = 0;

    for (Edge& edge : edges) {
        if (uf.find(edge.src) != uf.find(edge.dest)) {
            result.push_back(edge);
            totalWeight += edge.weight;
            uf.unionSets(edge.src, edge.dest);
        } }

    cout << "Edges in MST:\n";
    for (Edge& edge : result)
        cout << edge.src << " - " << edge.dest << "\t" << edge.weight << endl;
    cout << "Total weight: " << totalWeight << endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}  };

    kruskalMST(edges, V);

    return 0; }
