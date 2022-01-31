#include <iostream>
#include <vector>

void dfs(int u, vector<vector<int> > &adj, vector<bool> &vis) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v, adj, vis);
    cout << “Done visiting node: “ << u + 1 << endl;
}

int main() {
    int node, edges, u, v;
    cin >> node >> edges;
    vector<vector<int> > adj(node);
    vector<bool> vis(node);
    for(int i = 1; i <= edges; ++i) {
        cin >> u >> v;
        --u, --v;      
        adj[u].push_back(v);
adj[v].push_back(u);
}

dfs(0, adj, vis);  
return 0;
}  
