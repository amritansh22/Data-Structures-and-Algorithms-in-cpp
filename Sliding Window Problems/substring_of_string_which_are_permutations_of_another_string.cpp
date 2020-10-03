/* 
Problem:
Find all substrings of a string that are permutations of another string.
(Find Anagrams)

Using Sliding Window Technique

Example:

string1: 'ABCCDBAC'
string2: 'ABC'
o/p:
Anagram 'ABC' present at index 0
Anagram 'BAC' present at index 5

*/

#include <iostream>
#include <string>
#include <unordered_multiset>
using namespace std;

void findAllAnagrams(string str1, string str2)
{
	int m, n;

	// invalid input
	if ((m = str2.length()) > (n = str1.length()))
		return;

	unordered_multiset<char> window;

	unordered_multiset<char> set;

	for (int i = 0; i < m; i++)
		set.insert(str2[i]);

	for (int i = 0; i < n; i++)
	{
		if (i < m)
			window.insert(str1[i]);
	
		else
		{
            // If all characters in current window matches that of
			// string2, we found an anagram
			if (window == set)
			{
				cout << "Anagram " << str1.substr(i - m, m) <<
					" present at index " << i - m << '\n';
			}
		
			auto itr = window.find(X[i - m]);
			if (itr != window.end())
				window.erase(itr);

			window.insert(str1[i]);
		}
	}

	// if last m characters of string1 matches that of string2,
	// we found an anagram
	if (window == set)
	{
		cout << "Anagram " << X.substr(n - m, m) <<
			" present at index " << n - m << '\n';
	}
}

int main()
{
	string str1;
	string str2;

	findAllAnagrams(X, Y);

	return 0;
}

//Time complexity: O((n-m)*m)
// n -> length of first string 
// m -> length of second string