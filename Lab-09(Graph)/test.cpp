#include<bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 10;
const int MAX_EDGES = 10;

class Graph{
    int adj[MAX_VERTICES][MAX_EDGES];
    int count[MAX_VERTICES];
    int vertices;
    bool isDirected;

    public:
    Graph(int v,bool directed){
        vertices = v;
        isDirected = directed;

        for(int i=0;i<vertices;i++){
            count[i] = 0;
            for(int j=0;j<MAX_EDGES;j++){
                adj[i][j] = -1;
            }
        }
    }

    void addEdge(int u,int v){
        adj[u][count[u]] = v;
        count[u]++;

        if(!isDirected){
            adj[v][count[v]] = u;
            count[v]++;
        }
    }

    void BFS_Traversal(int start){
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;
        visited[start] = true;
        queue[rear++] = start;

        cout<<"BFS Traversal starting from vertex "<<start<<": ";

        while(front<rear){
            int current = queue[front++];
            cout<<current<<" ";
            for(int i=0;i<count[current];i++){
                int neighbor = adj[current][i];
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }
        cout<<endl;
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

    g.BFS_Traversal(0);

    return 0;
}