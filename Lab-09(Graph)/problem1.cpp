#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;
const int MAX_EDGES = 10;

class Graph {
    int adj[MAX_VERTICES][MAX_EDGES]; // adjacency list using 2D array
    int count[MAX_VERTICES];          // number of neighbors for each vertex
    int vertices;
    bool isDirected;

public:
    Graph(int v, bool directed) {
        vertices = v;
        isDirected = directed;

        // Initialize all entries
        for (int i = 0; i < vertices; i++) {
            count[i] = 0;
            for (int j = 0; j < MAX_EDGES; j++) {
                adj[i][j] = -1; // -1 means no edge
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][count[u]] = v;
        count[u]++;

        if (!isDirected) {
            adj[v][count[v]] = u;
            count[v]++;
        }
    }

    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < count[i]; j++) {
                cout << adj[i][j] << " -> ";
            }
            cout << "NULL" << endl;
        }
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

    cout << "\nAdjacency List of the Graph:" << endl;
    g.printGraph();

    return 0;
}