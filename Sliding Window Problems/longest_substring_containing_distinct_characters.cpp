/* 
Problem:
Given a string, find the logest substring of given string 
containing distinct characters.

Using Sliding Window Technique

Example:

string: 'hacktoberfest'
o/p is 'hacktoberf'

string: 'abaa'
o/p is 'ab'

*/

#include <iostream>
#include <vector>
using namespace std;

#define CHAR_RANGE 128

string longestSubstr(string str, int n)
{
	vector<bool> window(CHAR_RANGE);

	int begin = 0, end = 0;

	for (int low = 0, high = 0; high < n; high++)
	{
		if (window[str[high]])
		{
			// remove characters from the left of the window till
			// we encounter current character
			while (str[low] != str[high])
				window[str[low++]] = false;

			low++;		
		}
		else
		{
			// if current character is not present in the current
			// window, include it
			window[str[high]] = true;

			if (end - begin < high - low)
			{
				begin = low;
				end = high;
			};
		}
	}

	return str.substr(begin, end - begin + 1);
}

int main()
{
	string str;

    cout << "Enter string : ";
    cin >> str;

	int n = str.length();
	cout << longestSubstr(str, n);

	return 0;
}

// Time Complexity: O(n)
