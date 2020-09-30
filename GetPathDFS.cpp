/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
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
using namespace std;


vector <int> getPath(int** edges,int n,int start,int end,bool *visited){
  

  visited[start]=true;
  if(start==end){
    vector <int> temp;
    temp.push_back(start);
    return temp;
  }
    
  vector <int> ans;
  for(int i=0;i<n;i++){

    if(i==start)
      continue;
    
    if(edges[start][i] && !visited[i]){
      ans=getPath(edges,n,i,end,visited);
      
      if(!ans.empty()){
          ans.push_back(start);
          return ans;
      }
    }
  }
  return ans;
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

  vector <int> ThePath;
  ThePath=getPath(edges,V,s,e,visited);

  //Print Path
  for(int i=0;i<ThePath.size();i++)
    cout<<ThePath[i]<<" ";
  
  return 0;
}