// C++ Program to find the maximum for 
// each and every contiguous subarray of size k. 
#include <bits/stdc++.h> 
using namespace std; 

// Method to find the maximum for each 
// and every contiguous subarray of size k. 
void printKMax(int arr[], int n, int k) 
{ 
	int j, max; 

	for (int i = 0; i <= n - k; i++) 
	{ 
		max = arr[i]; 

		for (j = 1; j < k; j++) 
		{ 
			if (arr[i + j] > max) 
				max = arr[i + j]; 
		} 
		cout << max << " "; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	printKMax(arr, n, k); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
