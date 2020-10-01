//Iterative implementation of BFS
//Contributed by Kartikey Sharma

#include <bits/stdc++.h>
using namespace std;

// Data structure to store graph edges
struct Edge {
	int src, dest;
};

class Graph
{
public:
	vector<vector<int>> adjList;

	Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);
		
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

// Perform BFS on graph starting from vertex v
void BFS(Graph const &graph, int v, vector<bool> &discovered)
{
	queue<int> q;
	discovered[v] = true;
	q.push(v);

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << v << " ";
		
		for (int u : graph.adjList[v])
			if (!discovered[u])
			{
				discovered[u] = true;
				q.push(u);
			}
	}
}


int main()
{
	// sample edges
	vector<Edge> edges = 
	{
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
		// vertex 0, 13 and 14 are single nodes
	};

	int N = 15;

	Graph graph(edges, N);
	vector<bool> discovered(N, false);

	// Do BFS traversal from all undiscovered nodes to
	// cover all unconnected components of graph
	for (int i = 0; i < N; i++) 
	{
		if (discovered[i] == false) 
		{
			// start BFS traversal from vertex i
			BFS(graph, i, discovered);
		}
	}

	return 0;
}
