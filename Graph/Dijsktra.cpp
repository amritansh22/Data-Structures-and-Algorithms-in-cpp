#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << endl;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define INF 1000000000
#define MAXN 1000005
#define EPS 1e-9

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pllll;
typedef std::set<int> si;
typedef std::set<ll> sll;
typedef std::unordered_map<int , int> mii;
typedef std::unordered_map<ll , ll> mllll;
typedef std::unordered_map<char , int> mci;
typedef std::unordered_map<char , ll> mcll;

ll N;
bool vis[MAXN];
vll dist(MAXN);
std::vector<pllll> adj_dijkstra[MAXN]; //{v, w}

void dijkstra(int s) {
    FOR(i, 0, N) {
        dist[i] = INF;
        vis[i] = false;
    }
    std::priority_queue<pllll> q; //{w, v}
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        ll u = q.top().se; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto pr : adj_dijkstra[u]) {
            ll v, w;
            std::tie(v, w) = pr;
            if(vis[v]) continue;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
}

int main()
{
    return 0;
}
