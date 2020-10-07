#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define pcc pair<char, char> 
using namespace std;

vector<pair<int, pcc>> adj_list[2000];

int main()
{
    int n, e;
    cout << "Enter no. of vertices: ";
    cin >> n;
    cout << "Enter no. of edges: ";
    cin >> e;
    char u, v;
    int weight;
    while (e--) {
        cin >> u >> v >> weight;
        adj_list[(int)u].push_back({weight, {v, u}});
        adj_list[(int)v].push_back({weight, {u, v}});
    }
    set<char> MST_vertex_list;
    vector <pcc> MST_edge_list;
    priority_queue <pair<int, pcc>, vector<pair<int, pcc>>, greater<pair<int, pcc>>> min_heap;
    MST_vertex_list.insert((int)'a');
    for (int i = 0;i < adj_list[(int)'a'].size();i++) {
        min_heap.push(adj_list[(int)'a'][i]);
    }
    while (min_heap.size() > 0)
    {
        char temp = min_heap.top().second.first;
        if(MST_vertex_list.find(temp) == MST_vertex_list.end()) {
            MST_edge_list.push_back(min_heap.top().second);
            MST_vertex_list.insert(temp);
            min_heap.pop();
            for(int i = 0;i < adj_list[(int)temp].size();i++) {
                if (MST_vertex_list.find(adj_list[(int)temp][i].second.first) == MST_vertex_list.end())
                    min_heap.push(adj_list[(int)temp][i]);
            }
        }
        else {
            min_heap.pop();
        }
    }
    for (int i = 0;i < MST_edge_list.size();i++) {
        cout << MST_edge_list[i].first << " " << MST_edge_list[i].second << "\n";
    }
}
