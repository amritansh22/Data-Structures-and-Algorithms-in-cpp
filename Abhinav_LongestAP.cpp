
#include <iostream> 
using namespace std; 

int lenghtOfLongestAP(int set[], int n) 
{ 
	if (n <= 2) return n; 

	int L[n][n]; 
	int llap = 2; // Initialize the result 

	for (int i = 0; i < n; i++) 
		L[i][n-1] = 2; 

	for (int j=n-2; j>=1; j--) 
	{ 
		int i = j-1, k = j+1; 
		while (i >= 0 && k <= n-1) 
		{ 
		if (set[i] + set[k] < 2*set[j]) 
			k++; 

		else if (set[i] + set[k] > 2*set[j]) 
		{ L[i][j] = 2, i--; } 

		else
		{ 
			L[i][j] = L[j][k] + 1; 

			llap = max(llap, L[i][j]); 

			i--; k++; 
		} 
		} 

		while (i >= 0) 
		{ 
			L[i][j] = 2; 
			i--; 
		} 
	} 
	return llap; 
} 

int main() 
{ 
	int set1[] = {1, 7, 10, 13, 14, 19}; 
	int n1 = sizeof(set1)/sizeof(set1[0]); 
	cout << lenghtOfLongestAP(set1, n1) << endl; 

	int set2[] = {1, 7, 10, 15, 27, 29}; 
	int n2 = sizeof(set2)/sizeof(set2[0]); 
	cout << lenghtOfLongestAP(set2, n2) << endl; 

	int set3[] = {2, 4, 6, 8, 10}; 
	int n3 = sizeof(set3)/sizeof(set3[0]); 
	cout << lenghtOfLongestAP(set3, n3) << endl; 

	return 0; 
} 
