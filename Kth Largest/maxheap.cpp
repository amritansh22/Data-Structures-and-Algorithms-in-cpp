#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the K'th largest element in the
// array using max-heap
int FindKthLargest(vector<int> const &A, int k)
{
	// create a max-heap using std::priority_queue
	// from all elements of the vector
	priority_queue<int, vector<int>> pq(less<int>(), A);

	// pop from max-heap exactly (k-1) times
	while (--k) {
		pq.pop();
	}

	// return the root of max-heap
	return pq.top();
}

// Find K'th largest element in an array
int main()
{
	vector<int> A  = { 7, 4, 6, 3, 9, 1 };
	int k = 2;

	cout << "K'th largest element in the array is " <<
			FindKthLargest(A, k);

	return 0;
}

//output K'th largest element in the array is 7
