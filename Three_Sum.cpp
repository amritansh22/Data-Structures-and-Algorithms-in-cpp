// Three_Sum
/*
	Given an array of integers nums(sorted in ascending order) and an integer target,
	return indices(zero indexed) of the three numbers if exists such that they sum adds up to target.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> Three_Sum(vector<int> &arr, int target) {

	for (int i = 0; i < arr.size() - 2; i++) {
		int low = i + 1, high = arr.size() - 1;
		while (low <= high) {
			int sum = arr[low] + arr[high];
			if (target == sum) {
				return {i, low, high};
			}
			else if (target < sum) {
				high--;
			}
			else {
				low++;
			}
		}
	}
	return { -1, -1, -1};
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

	vector<int> p = Three_Sum(arr, target);

	if (p[0] == -1 && p[1] == -1 && p[2] == -1)
		cout << "Three numbers not exist in array" << endl;
	else
		cout << "Indices are " << p[0] << ", " << p[1] << " and " << p[2] << endl;
	return 0;
}