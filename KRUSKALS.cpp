#include <iostream>
#include <vector>
#include <algorithm>
#define pcc pair<char, char> 
using namespace std;

char par[128];

char find(char c)
{
    while (par[(int)c] != -1)
        c = par[(int)c];
    return c;
}

int main()
{
    vector<pair<int, pcc> > edge_list, MST_edge_list;
    int n, e;
    cout << "Enter no. of edges: ";
    cin >> e;
    char u, v;
    int weight;
    cout << "Enter the edges:\n";
    for (int i = 0;i < e;i++) {
        cin >> u >> v >> weight;
        edge_list.push_back({weight, {u, v}});
    }
    sort(edge_list.begin(), edge_list.end());
    for (int i = 0;i < 128;i++)
        par[i] = -1;
    for (int i = 0;i < e;i++) {
        u = edge_list[i].second.first;
        v = edge_list[i].second.second;
        weight = edge_list[i].first;
        if (find(u) != find(v)) {
            par[find(u)] = find(v);
            MST_edge_list.push_back({weight, {u, v}});
        }
    }
    cout << "\nThe edges in the MST are:\n";
    for (int i = 0;i < MST_edge_list.size();i++) {
        cout << MST_edge_list[i].second.first << " " << MST_edge_list[i].second.second << " " << MST_edge_list[i].first << "\n";
    }
}
