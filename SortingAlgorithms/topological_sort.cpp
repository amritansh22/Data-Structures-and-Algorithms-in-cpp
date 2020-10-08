#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void topologicalSortUtil(vector<int> adj[], int v, bool* visited, stack<int>& s) {
  visited[v] = true;

  vector<int>::iterator it;
  for (it = adj[v].begin(); it != adj[v].end(); ++it) {
    if (!visited[*it])
      topologicalSortUtil(adj, *it, visited, s);
  }

  s.push(v);
}

void topologicalSort(vector<int> adj[], int V) {
  stack<int> s;
  
  bool* visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      topologicalSortUtil(adj, i, visited, s);
    }
  }

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

int main() {
  int V = 5;
  vector<int> adj[V];
  addEdge(adj, 0, 1); 
  addEdge(adj, 0, 2); 
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3); 
  addEdge(adj, 3, 4); 

  topologicalSort(adj, V);
  return 0;
}