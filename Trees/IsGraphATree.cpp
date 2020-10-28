
//Is the given graph a tree ?
// Two conditions
//1. Should not contain a cycle : no of edges = n-1
//2. 1 connected component

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define f(i, a, n) for (i = a; i < n; i++)
#define fe(i, a, n) for (i = a; i <= n; i++)
#define w(x)  \
	int x;    \
	cin >> x; \
	while (x--)
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x

void sks()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> adj[10001];
int vis[10001];

void dfs(int node)
{
	vis[node] = 1;

	for (int child : adj[node])
	{
		if (!vis[child])
			dfs(child);
	}
}

int main()
{
	sks();

	int n, m, a, b, i, cv = 0;
	cin >> n >> m;

	fe(i, 1, m)
	{
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	cv = 0;
	fe(i, 1, n)
	{
		if (vis[i] == 0)
		{
			dfs(i);
			cv++;
		}
	}

	if (cv == 1 && m == n - 1)
		cout << "YES" << endl;

	else
		cout << "NO" << endl;

	return 0;
}
