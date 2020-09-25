// Merge Sort
// Time complexity: O(N*log(N))


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void merge(vector<int> &a, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<int> Left(n1), Right(n2);
	for(i = 0; i < n1; i++) Left[i] = a[l + i];
	for(i = 0; i < n2; i++) Right[i] = a[m + 1 + i];
	
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2){
		if(Left[i] <= Right[j])
			a[k] = Left[i++];
		else
			a[k] = Right[j++];
		k++;
	}
	
	while(i < n1)
		a[k++] = Left[i++];
	while(j < n2)
		a[k++] = Right[j++];
}
void mergeSort(vector<int> &a, int l, int r){
	if(l < r){
		int m = (r + l) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int main(){
	cout << "Enter number of elements: \n";
	int N; cin >> N;
	vector<int> a(N);
	int i;
	
	cout << "Enter elements of array: \n";
	for(i = 0; i < N; i++){
		cin >> a[i];
	}
	
	mergeSort(a, 0, N - 1);
	
	for(i = 0; i < N; i++) 
		cout << a[i] << " ";
}