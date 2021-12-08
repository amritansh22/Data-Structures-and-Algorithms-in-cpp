/*
Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :

BFS Traversal (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:

4 4
0 1
0 3
1 2
2 3

Sample Output 1:

0 1 3 2


*/
#include <iostream>
#include <queue>
using namespace std;

void bfs(int **edges,int n,int start,bool *visited){

  queue<int> q;
  q.push(start);
  visited[start]=true;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    cout<<node<<" ";
    

    for(int i=0;i<n;i++){
      if(edges[node][i] && !visited[i]){
        q.push(i);
        visited[i]=true;
      }
    }
  }
  cout<<endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    int **edges=new int*[V];
    //intialization
    for(int i=0;i<V;i++){
      edges[i]=new int[V];
      for(int j=0;j<V;j++)
        edges[i][j]=0;
    }

    for(int i=0;i<E;i++){
      int a,b;
      cin>>a>>b;
      edges[a][b]=1;
      edges[b][a]=1;
    }
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
      visited[i]=false;
    
    bfs(edges,V,0,visited);

  return 0;
}
