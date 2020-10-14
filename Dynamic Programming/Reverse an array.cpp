#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int start=0, end=n-1;
	
	while(end>start){
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
	
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
	
	return 0;
}
