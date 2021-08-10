// Two_Sum in O(n)
/*
	Given an array of integers and an integer target,
	return indices(zero indexed) of the two numbers if exists such that they sum adds up to target.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> Two_Sum(vector<int> &arr, int target) {

	unordered_map<int,int> mpi;
	for(int i=0;i < arr.size(); ++i)
		mpi[arr[i]]=i;


	for(int i=0; i< arr.size(); ++i){
		if(target  == 2*arr[i]){     // for the case when target is equal to sum of two repeating elements
			if(mpi[arr[i]] != i)       // like arr = {2,3,2}, target = 4
			return {i,mpi[arr[i]]};
		}
		else {
			if(mpi.find(target-arr[i]) != mpi.end())  //check if target - given element is present in hashmap
			return {i,mpi[target-arr[i]]};
		}
	}

	return {-1,-1};
}

int main()
{
	cout << "Enter the size of the array: ";
	int n;
	cin >> n;

	cout << "Enter the array: " << '\n';
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "Enter the target: ";
	int target;
	cin >> target;

	vector<int> p = Two_Sum(arr, target);

	if (p[0] == -1 && p[1] == -1)
		cout << "Two numbers with sum "<<target<< " are not present in the array" << endl;
	else
		cout << "Indices are " << p[0] << " and " << p[1] << endl;
	return 0;
}
