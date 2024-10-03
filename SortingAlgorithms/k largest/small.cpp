// C++ code for k largest elements in an array
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < k; i++)
		cout << arr[i] << " ";
}

// driver program
int main()
{
	int arr[] = { 1, 23, 12, 9, 30, 2, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	kLargest(arr, n, k);
}


