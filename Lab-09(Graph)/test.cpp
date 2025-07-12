#include<bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 10;
const int INF = 1e9;

class PrimsMST{
   int adj[MAX_VERTICES][MAX_VERTICES];
   int vertices,totalEdges;

   public:
   PrimsMST(int v){
      vertices = v;
      for(int i=0;i<vertices;i++){
         for(int j=0;j<vertices;j++){
            adj[i][j] = 0;
         }
      }
   }

   void addEdges(int e){
      totalEdges = e;
      for(int i=0;i<totalEdges;i++){
         int u,v,w;
         cin>>u>>v>>w;
         adj[u][v] = w;
         adj[v][u] = w;
      }
   }

   int minIndex(int key[],bool visited[]){
      int min = INF,minIndex = -1;

      for(int i=0;i<vertices;i++){
         if(!visited[i] && key[i]<min){
            min = key[i];
            minIndex = i;
         }
      }
      return minIndex;
   }

   void buildMST(){
      int parent[MAX_VERTICES];
      bool visited[MAX_VERTICES];
      int key[MAX_VERTICES];

      for(int i=0;i<vertices;i++){
         key[i] = INF;
         visited[i] = false;
      }

      key[0] = 0;
      parent[0] = -1;

      for(int i=0;i<vertices-1;i++){
         int u = minIndex(key,visited);
         visited[u] = true;
         for(int v=0;v<vertices;v++){
            if(adj[u][v] && !visited[v] && adj[u][v]<key[v]){
               key[v] = adj[u][v];
               parent[v] = u;
            }
         }
      }

      int totalWeitgh = 0;
      for(int i=1;i<vertices;i++){
         cout<<parent[i]<<" "<<i<<" : "<<adj[i][parent[i]]<<endl;
         totalWeitgh += adj[i][parent[i]];
      }
   }
};