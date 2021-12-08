/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :

Path from v1 to v2 in reverse order (separated by space)

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :

4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :

3 0 1

Sample Input 2 :

6 3
5 3
0 1
3 4
0 3

Sample Output 2 :

 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


void getPathBFS(int **edges,int n,int start,int end,bool* visited,unordered_map<int,int> &prec){
  
  queue<int> q;
  q.push(start);

  while(!q.empty()){
    int node=q.front();
    q.pop();
    visited[node]=true;

    if(node==end)
      return;
    for(int i=0;i<n;i++){
      if(edges[node][i] && !visited[i]){
        q.push(i);
        if(prec.count(i)==0)
          prec[i]=node;
      }
    }
  }
}

int main()
{
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

  int s,e;
  cin>>s>>e;
  bool* visited=new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;

  unordered_map<int,int> prec;
  getPathBFS(edges,V,s,e,visited,prec);

  if(visited[e]){
    int t=e;
    while(t!=s){
      cout<<t<<" ";
      t=prec[t];
    }
    cout<<t;
  }

  return 0;
}
