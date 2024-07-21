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
vll adj[MAXN];

void toposort() {
    vll indegree(N);
    FOR(i, 0, N) {
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    std::queue<ll> q;
    FOR(i, 0, N) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vll result;
    while(!q.empty()) {
        ll node = q.front(); q.pop();
        result.pb(node);

        for(auto it : adj[node]){
            indegree[it]--;

            if(indegree[it] == 0)
                q.push(it);
        }
    }

    if(result.size() != N)
        std::cout<<"Cycle Detected";
    else
        std::cout<<"No Cycle";
}

int main()
{
    return 0;
}
