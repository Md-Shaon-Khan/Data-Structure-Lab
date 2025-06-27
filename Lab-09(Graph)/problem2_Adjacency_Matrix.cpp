#include<bits/stdc++.h>
using namespace std;

const int Max_VERTICES = 10;

class Graph{
    int adj[Max_VERTICES][Max_VERTICES];
    int vertices;
    bool isDirected;
    
    public:
    Graph(int v,bool directed){
        vertices = v;
        isDirected = directed;

        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u,int v){
        adj[u][v] = 1;

        if(!isDirected){
            adj[v][u] = 1;
        }
    }

    void printGraph(){
        cout<<"Adjacency Matrix: "<<endl;
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    int vertices,edges,directed;
    cout<<"Enter number of vertices: ";
    cin>>vertices;

    cout<<"Enter number of edges: ";
    cin>>edges;

    cout<<"Is the graph directes?(1 = Yes, 0 = No): ";
    cin>>directed;

    Graph g(vertices,directed);

    cout<<"Enter edges(u v): "<<endl;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    g.printGraph();


    return 0;
}