#include <iostream> 
#include <list> 
using namespace std; 
 
class DFSGraph 
{ 
	int V;    								// No. of vertices 
	list<int> *adjList;    					// adjacency list 
	void DFS_func(int v, bool visited[]);  	// DFS function 
	public: 
    DFSGraph(int V)
	{
		this->V = V; 
		adjList = new list<int>[V]; 
	}
	//function to add W to the V's list
    void addEdge(int v, int w)
	{
		adjList[v].push_back(w);
	}
	void DFS();    // DFS traversal function 
}; 

void DFSGraph::DFS_func(int v, bool visited[]) 
{ 
    // current node v is visited 
	visited[v] = true; 
	cout << v << " "; 
    // recursively process all the adjacent vertices of the node 
	list<int>::iterator i; 
	for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
	{
		if(!visited[*i]) 
			DFS_util(*i, visited); 
	}
} 
	
// DFS traversal 
void DFSGraph::DFS() 
{ 
	//Intitially no vertex is visited
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
	{
		visited[i] = false; 
	}
   	//Explore each vertex recursively
	for (int i = 0; i < V; i++) 
	{
		if (visited[i] == false) 
			DFS_func(i, visited); 
	}
}
 
// Main function
int main() 
{ 
	DFSGraph gdfs(5); 
	gdfs.addEdge(0, 1); 
	gdfs.addEdge(0, 2); 
	gdfs.addEdge(0, 3);
	gdfs.addEdge(1, 2); 
	gdfs.addEdge(2, 4);
	gdfs.addEdge(3, 3); 
	gdfs.addEdge(4, 4);

	cout << "Depth-first traversal for the given graph:"<<endl; 
	gdfs.DFS(); 
			
	return 0; 
}
