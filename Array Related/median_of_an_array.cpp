// C++ program for the above approach 
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std; 

// Function for calculating the median 
double findMedian(vector<int> a, 
				int n) 
{ 
	// If size of the arr[] is even 
	if (n % 2 == 0) { 
		// Applying nth_element on n/2th index for getting sorted element
		nth_element(a.begin(), 
					a.begin() + n / 2, 
					a.end()); 

		// Applying nth_element 
		// on (n-1)/2 th index 
		nth_element(a.begin(), 
					a.begin() + (n - 1) / 2, 
					a.end()); 

		// Find the average of value at 
		// index N/2 and (N-1)/2 
		return (double)(a[(n - 1) / 2] 
						+ a[n / 2]) 
			/ 2.0; 
	} 

	// If size of the arr[] is odd 
	else { 
		// Applying nth_element on n/2 for getting sorted element
		nth_element(a.begin(), 
					a.begin() + n / 2, 
					a.end()); 

		// Value at index (N/2)th 
		// is the median 
		return (double)a[n / 2]; 
	} 
} 

int main() 
{ 
    int i,n,input;
    vector<int> arr;
	cout << "Enter number of elements in the array" << endl;
	cin >> n;
    cout << "Enter the values: (space seperated)" << endl;
	for (i = 0; i < n; i++) 
	{
		cin >> input;
		arr.push_back(input);
	}
    cout << "Array values are:" << endl;
    for (i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
	cout << endl
	    << "Median = "
		<< findMedian(arr, arr.size()) 
		<< endl; 
	return 0; 
} 
