#include <iostream>
using namespace std;

const int MAX = 100;

class Graph {
    int adj[MAX][MAX];  
    int V;

public:
    Graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;  
    }

    bool dfs(int node, bool visited[], int parent) {
        visited[node] = true;

        for (int neighbor = 0; neighbor < V; neighbor++) {
            if (adj[node][neighbor]) { 
                if (!visited[neighbor]) {
                    if (dfs(neighbor, visited, node))
                        return true;
                }
                else if (neighbor != parent) {
                    return true; 
                }
            }
        }

        return false;
    }

    bool hasCycle() {
        bool visited[MAX] = {false};

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, -1))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.hasCycle())
        cout << "Cycle Detected." << endl;
    else
        cout << "No Cycle." << endl;

    return 0;
}
