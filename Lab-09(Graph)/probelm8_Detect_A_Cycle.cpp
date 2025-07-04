#include <bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 10;
const int MAX_EDGES = 10;

class Graph {
    int adj[MAX_VERTICES][MAX_EDGES];
    int count[MAX_VERTICES];
    int vertices;
    bool isDirected;

public:
    Graph(int v, bool directed) {
        vertices = v;
        isDirected = directed;
        for (int i = 0; i < vertices; i++) {
            count[i] = 0;
            for (int j = 0; j < MAX_EDGES; j++) {
                adj[i][j] = -1;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][count[u]++] = v;
        if (!isDirected) {
            adj[v][count[v]++] = u;
        }
    }

    bool hasCycleUtil(int current, bool visited[], int parent) {
        visited[current] = true;

        for (int i = 0; i < count[current]; i++) {
            int neighbor = adj[current][i];

            if (!visited[neighbor]) {
                if (hasCycleUtil(neighbor, visited, current)) {
                    return true;
                }
            }
            else if (neighbor != parent) {
                // A visited node which is not the parent -> cycle found
                return true;
            }
        }

        return false;
    }

    void detectCycle() {
        bool visited[MAX_VERTICES] = {false};

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                if (hasCycleUtil(i, visited, -1)) {
                    cout << "Cycle detected in the graph." << endl;
                    return;
                }
            }
        }

        cout << "No cycle found in the graph." << endl;
    }
};

int main() {
    int vertices, edges, directed;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Is the graph directed? (1 = Yes, 0 = No): ";
    cin >> directed;

    Graph g(vertices, directed);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.detectCycle();

    return 0;
}