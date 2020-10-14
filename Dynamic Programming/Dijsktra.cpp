#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define pb(i) push_back(i)
#define mp(i,j) make_pair(i,j)
#define test ll t; cin>>t; while(t--)

#define v 9

int minDistance(int dist[], bool visited[]) 
{  
    int min = INT_MAX, minIndex; 
  
    f(i,0,v)
	{
		if (visited[i]==false && dist[i]<=min) 
		{
			min = dist[i];
			minIndex = i; 
		}   
	}
  
    return minIndex; 
} 

void print(int dist[]) 
{ 
    cout<<"Vertex \t\t Distance from Source"<<endl; 
    
    f(i,0,v)
    {
    	cout<<i<<"\t\t "<<dist[i]<<endl;
	}
} 

void dijsktra(int g[][v], int s)
{
	int dist[v];
	bool visited[v];
	
	f(i,0,v)
	{
		dist[i] = INT_MAX;
		visited[i] = false;	
	} 
	
	dist[s] = 0;
	
	f(i,0,v-1)
	{
		int u = minDistance(dist,visited);
		visited[u] = true;
		
		f(j,0,v)
		{
			if (!visited[j] && g[u][j] && dist[u]!=INT_MAX && dist[u]+g[u][j]<dist[j])
			{
				dist[j] = dist[u] + g[u][j]; 
			}    
		}
	}
	
	print(dist);
}

int main()
{
    int g[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                   { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                   { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                   { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                   { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                   { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                   { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                   { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                   { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    //source vertex is 0
    dijkstra(g,0); 
	
    return 0;
}
