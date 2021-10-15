#include<bits/stdc++.h>
using namespace std;

// Recursion + Memorisation
int LongestCommonSubsequence(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
	if (i == s.length() || j == t.length())
		return 0;
	int &ans = dp[i][j];
	if (ans > -1)
		return ans;
	if (s[i] == t[j]) {
		ans = LongestCommonSubsequence(s, t, i + 1, j + 1, dp) + 1;
		return ans;
	}
	ans = max(LongestCommonSubsequence(s, t, i + 1, j, dp),
	          LongestCommonSubsequence(s, t, i, j + 1, dp));
	return ans;
}

int main()
{
	string s, t;
	cout << "Enter two strings to find the length of LCS present in both: \n";
	cin >> s >> t;
	vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
	int lcs = LongestCommonSubsequence(s, t, 0, 0, dp);
	cout << "length of LCS is " << lcs << endl;
	return 0;
}