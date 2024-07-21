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
vll rank(MAXN), size(MAXN), parent(MAXN);
std::vector<std::tuple<ll, ll, ll>> edges;

//Helping functions
void init() {
    FOR(i, 0, N) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
}

ll find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);

    //By rank
    if(a != b) {
        if(rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }

    //By size
    if(a != b) {
        if(size[a] < size[b])
            std::swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

//Actual Kruskal
void kruskal() {
    std::sort(all(edges));
    for(auto edge : edges) {
        ll u, v, w;
        std::tie(w, u, v) = edge;
        if(!same(u, v)) unite(u, v);
    }
}

int main()
{
    return 0;
}
