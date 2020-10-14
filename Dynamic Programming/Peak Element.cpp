#include<bits/stdc++.h>
using namespace std;

/********************************************************
Problem Statement:

	Given an array of n elements, find the 
	position of the element which is greater than 
	or equal to both of its neighboring elements.

Basic Idea:
	
	The naive approach is to use a simple linear scan.
	But we can do even better than that by using
	modified version of Binary Search which would run
	in time complexity of O(logn).

Note:
	
	This program uses 0-based indexing.

********************************************************/


int findPeakElement(vector<int>& arr, int n) {
    int l = 0, r = n - 1;
    while(l < r){
        int mid = (r-l)/2 + l;
        if(arr[mid] > arr[mid+1]){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}


int main(){
	
	int n;
	cin >> n;

	vector <int> arr(n);

	for(int& i : arr){
		cin >> i;
	}

	cout << "The peak is at position: " <<findPeakElement(arr, n);
}
