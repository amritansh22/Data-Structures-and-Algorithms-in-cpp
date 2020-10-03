#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define ll long long int
using namespace std;

class Graph{
    ll V;
    vector<ll> *arr;
private:
    /* data */
public:
    Graph(ll V);
    void addEdge(ll u, ll v);
    void BFS(ll s);
    void DFS(ll s);
};

Graph::Graph(ll V){
    this->V = V;
    arr = new vector<ll>[V];
}

void Graph::addEdge(ll u, ll v){
    arr[u].push_back(v);
}

void Graph::BFS(ll s){
    vector<bool> visit(V, false);
    visit.at(s) = true;
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        cout<<s<<" ";
        q.pop();
        for(ll i=0; i<arr[s].size(); i++){
            if(visit[arr[s][i]]==false){
                visit[arr[s][i]] = true;
                q.push(arr[s][i]);
            }
        }
    }
    cout<<endl;
}


void Graph::DFS(ll s){
    vector<bool> visit(V, false);
    visit.at(s) = true;
    stack<ll> st;
    st.push(s);
    while(!st.empty()){
        s = st.top();
        cout<<s<<" ";
        st.pop();
        for(ll i=0; i<arr[s].size(); i++){
            if(visit[arr[s][i]]==false){
                visit[arr[s][i]] = true;
                st.push(arr[s][i]);
            }
        }
    }
    cout<<endl;
}


int main(int argc, char const *argv[]){

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.DFS(2); 
    
    return 0;
}
