/* 
Problem:
Given an array and a positive number k, 
check whether the array contains any duplicate elements within range k.
If k is more than size of the array, the solution should check for duplicates in the complete array

Using Sliding Window Technique

Example:

A[] = {1, 2, 3, 4, 9, 3, 8, 1 }
k = 4
o/p:
Duplicates found
(element 3 is repeated at distance 3 which is <=k )

A[] = {1, 2, 3, 9, 1 }
k = 3
o/p:
No duplicates found
(element 1 is repeated at distance 4 which is >k) 

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool contains(unordered_set<int> const &set, int x) {
	return set.find(x) != set.end();
}

bool hasDuplicates(vector<int> &vec, int k)
{
	// create an empty set to store elements within range k
	unordered_set<int> window;

	for (int i = 0; i < vec.size(); i++)
	{
		// if the current element already exists in the window,
		// then it is repeated within range of k
		if (contains(window, vec[i])) {
			return true;
		}

		window.insert(vec[i]);

		if (i >= k) {
			window.erase(vec[i - k]);
		}
	}

	// we reach here when no element is repeated within range k
	return false;
}

int main()
{
	vector<int> vec = { 5, 6, 8, 2, 4, 6, 9 };
	int k = 4;

	if (hasDuplicates(vec, k)) {
		cout << "Duplicates found";
	}
	else {
		cout << "No Duplicates found";
	}

	return 0;
}

//Time complexity is O(n) and uses O(n) extra space