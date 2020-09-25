// Selection Sort
// Find the minimum element from the unsorted part of the array and put it at the beginning of the unsorted array.
// Time complexity: O(N^2)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	cout << "Enter number of elements: \n";
	int N; cin >> N;
	vector<int> a(N);
	int i, j, min_idx;
	
	cout << "Enter elements of array: \n";
	for(i = 0; i < N; i++){
		cin >> a[i];
	}
	
	// Selection Sort
	for(i = 0; i< N; i++){
		min_idx = i;
		for(j = i + 1; j < N; j++){
			if(a[j] < a[min_idx])
				min_idx = j;             // Find the index of minimum element
		}
		swap(a[i], a[min_idx]);         
	}
	
	//Print sorted array
	for(i = 0; i < N; i++)
		cout << a[i] << " ";
}