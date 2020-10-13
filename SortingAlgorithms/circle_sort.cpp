/*
Circle sort is an inplace sorting algorithm where elements
which are diametrically opposite are swapped to be in order.
This process is recursively repeated.
*/

/*
average case complexity = O(nlogn)
*/


#include<bits/stdc++.h>

//Change the test array below to test any array for the function.
#define test {9,1,81,2,7,3,6,5,1}
using namespace std;



// Function

//1. Recursive Circle Sort

bool circleSortHelper(vector<int> &nums, int start, int end){	
	
	if(start == end) return false ; // need to stop the recursion (base case)

	bool res = false; // variable to keep track if there occurred any swapping.
	// recursion will stop if no more swaps are left to be performed.

	int low  = start, high = end;

	while(low < high){
		// swap the two elements if they are not in order
		if(nums[low] > nums[high]){
			swap(nums[low], nums[high]);
			res = true;
		}
		low++ ; 
		high--;
	}
	/* 
	corresponding to odd sized arrays we need to
	handle a separate case for middle element
	*/ 
	if(low == high){
		if(nums[low] > nums[high + 1]){
			res = true;
			swap(nums[low], nums[high+1]);
		}
	}

	int mid = start + (end-start)/2;
	bool first = circleSortHelper(nums,start,mid);
	bool second = circleSortHelper(nums,mid+1,end);
	return res || first || second;
}

void circleSort(vector<int> &arr, int start, int end){
	while(circleSortHelper(arr,start,end)) ;
	/* 
	as long as there are subparts which are not completely sorted
	the while loop will not terminate
	*/
}



int main(){
	vector<int> arr(test);
	cout << "Unsorted array" << endl;
	for(int i : arr) cout << i << " " ;
	cout << endl;

	circleSort(arr,0,arr.size()-1);

	cout << "Sorted array" << endl;
	for(int i : arr) cout << i << " " ;
	cout << endl;
}