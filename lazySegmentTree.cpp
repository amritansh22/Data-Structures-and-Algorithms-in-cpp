#include<bits/stdc++.h>

using namespace std;

#define inf             1e18


int lazy[10000] = {0};
void lazyUpdate(int tree[], int s, int e, int l, int r, int val , int index) {
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (e != s) {
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}

	if (s > r or e < l) return;

	if (s >= l and e <= r) {
		tree[index] += val;
		if (e != s) {
			lazy[2 * index] += val;
			lazy[2 * index + 1] += val;
		}
		return;
	}

	int mid = (s + e) / 2;
	lazyUpdate(tree, s, mid, l, r, val, 2 * index);
	lazyUpdate(tree, mid + 1, e, l, r, val, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}

int lazyQuery(int tree[], int s, int e, int l, int r, int index) {
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (e != s) {
			lazy[2 * index] = lazy[index];
			lazy[2 * index + 1] = lazy[index];
		}
		lazy[index] = 0;
	}

	if (s > r or e < l) return inf;
	if (s >= l and e <= r) return tree[index];

	int mid = (s + e) / 2;
	int left = lazyQuery(tree, s, mid, l, r, 2 * index);
	int right = lazyQuery(tree, mid + 1, e, l, r, 2 * index + 1);
	return min(left, right);


}

void build(int a[], int tree[], int s, int e, int index) {
	if (s == e) {
		tree[index] = a[e];
		return;
	}
	int mid = (s + e) / 2;
	build(a, tree, s, mid, 2 * index);
	build(a, tree, mid + 1, e, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}


int32_t main()
{
    //An example of implementing this code
	// int a[] = {1, 3, 2, -5, 6, 4};
	// int n = sizeof(a) / sizeof(int);
	// int tree[4 * n + 1];
	// build(a, tree, 0, n - 1, 1);
	// lazyUpdate(tree, 0, n - 1, 0, 2, 10, 1);
	// return 0;
}
