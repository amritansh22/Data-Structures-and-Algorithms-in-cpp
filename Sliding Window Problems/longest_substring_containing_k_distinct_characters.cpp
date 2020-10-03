/* 
Problem:
Given a string and a positive number k, find the logest substring of given string 
containing k distinct characters.
If k is more than the number of distict characters in the string, return the whole string.

Using Sliding Window Technique

Example:
string: 'zootopia'
for k = 2, o/p is 'ooto'
for k = 3, o/p is 'zooto'

*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

#define CHAR_RANGE 128

string longestSubstr(string str, int k, int n)
{
	// for longest substring boundaries
	int end = 0, begin = 0;

	unordered_set<char> window;

	// array to store frequency of characters present in
	// current window
	int freq[CHAR_RANGE] = { 0 };

	for (int low = 0, high = 0; high < n; high++)
	{
		window.insert(str[high]);
		freq[str[high]]++;

		while (window.size() > k)
		{
			// if the frequency of leftmost character becomes 0 after
			// removing it in the window, remove it from set as well
			if (--freq[str[low]] == 0)
				window.erase(str[low]);

			low++;		
		}

		if (end - begin < high - low)
		{
			end = high;
			begin = low;
		}
	}

	return str.substr(begin, end - begin + 1);
}

int main()
{
	string str;
	int k;

    cout << "Enter string and value of k: ";
    cin >> str >> k; 

	int n = str.length();
	cout << longestSubstr(str, k, n);

	return 0;
}

/*
Time Complexity: O(n)
As it does 2 traversals of the given string