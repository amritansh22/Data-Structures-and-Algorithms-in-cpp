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
bool seen[MAXN];
vll dist(MAXN), adj[MAXN];

void bfs(int x) {
    std::queue<ll> q;
    seen[x] = true;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(seen[v]) continue;
            seen[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    return 0;
}
