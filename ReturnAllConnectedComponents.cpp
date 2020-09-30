/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :

Different components in new line

Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:

4 2
0 1
2 3

Sample Output 1:

0 1 
2 3 

Sample Input 2:

4 3
0 1
1 3 
0 3

Sample Output 2:

0 1 3 
2


 */
#include <bits/stdc++.h>
using namespace std;

void popCon(int **edges,int n,int start,bool* visited,vector<int> &v){
    
    v.push_back(start);
    visited[start]=true;
    
    for(int i=0;i<n;i++){
        
        if(i==start)
            continue;
        
        if(edges[start][i] && !visited[i])
            popCon(edges,n,i,visited,v);
    }
}


void printComponents(vector <vector <int> >&ans){
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    
    int **edges=new int*[V];
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
    
    vector <vector <int> > ans;
    vector <int> temp;
    for(int i=0;i<V;i++){
        
        if(!visited[i]){
            popCon(edges,V,i,visited,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        
    }
    
    printComponents(ans);
    
    

  return 0;
}
