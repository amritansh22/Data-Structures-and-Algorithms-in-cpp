/* 
Problem:
Given an array of integers, 
print all maximum size sub-arrays having all distinct elements in them

Using Sliding Window Technique

Example:

A[] = {1, 2, 3, 3, 2, 4, 5}
o/p:
{1, 2, 3}
{3, 2, 4, 5}
*/

#include <iostream>
#include <unordered_map>
using namespace std;

void printSubArray(int A[], int i, int j, int n)
{
    //invalid input
	if (i < 0 || i > j || j >= n) 
		return;

	for (int index = i; index < j; index++)
		cout << A[index] << ", " ;

	cout << A[j] << endl;
}

void calculate(int A[], int n)
{
	// Map to mark elements as visited in the current window
	unordered_map<int, bool> visited;

	int right = 0, left = 0;

	while (right < n)
	{
		// keep increasing the window size if all elements in the
		// current window are distinct
		while (right < n && !visited[A[right]])
		{
			visited[A[right]] = true;
			right++;
		}

		printSubArray(A, left, right - 1, n);

		// As soon as duplicate is found (A[right]),
		// terminate the above loop and reduce the window's size
		// from its left to remove the duplicate
		while (right < n && visited[A[right]])
		{
			visited[A[left]] = false;
			left++;
		}
	}
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
 
    int A[n];
    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++)
        cin >> A[i]; 

	calculate(A, n);

	return 0;
}

//Time complexity is O(n) and uses O(n) extra space to mark elements of the current window
