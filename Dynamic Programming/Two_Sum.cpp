// Two_Sum
/*
	Given an array of integers nums(sorted in ascending order) and an integer target,
	return indices(zero indexed) of the two numbers if exists such that they sum adds up to target.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> Two_Sum(vector<int> &arr, int target) {

	int low = 0, high = arr.size() - 1;
	while (low <= high) {
		int sum = arr[low] + arr[high];
		if (target == sum) {
			return {low, high};
		}
		else if (target < sum) {
			high--;
		}
		else {
			low++;
		}
	}
	return { -1, -1};
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
		cout << "Two numbers not exist in array" << endl;
	else
		cout << "Indices are " << p[0] << " and " << p[1] << endl;
	return 0;
}
