/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :

Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M

Output Return Format :

The count the number of connected groups of islands

Sample Input :

2 1
1
2

Sample Output :

1 

 */


#include <bits/stdc++.h>
using namespace std;

void dfs(vector <vector <int> > &adj,int node,bool* visited){
    visited[node]=true;
    
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
            dfs(adj,adj[node][i],visited);
    }
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    vector <vector <int> > adj(n+1);
    
    for(int i=0;i<m;i++){
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    
    bool* visited=new bool[n+1];
    for(int i=1;i<=n;i++)
        visited[i]=false;
    
    int conI=0;
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(adj,i,visited);
            conI++;
        }
    }
    return conI;
}


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}