// Minimum Path Sum
/*
	Given a m x n grid filled with non-negative numbers,
	find a path from top left to bottom right which minimizes the sum of all numbers along its path.

	Note: You can only move either down or right at any point in time.
*/
#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
	for (int i = 1; i < grid.size(); i++) {
		grid[i][0] += grid[i - 1][0];
	}
	for (int i = 1; i < grid[0].size(); i++) {
		grid[0][i] += grid[0][i - 1];
	}

	for (int i = 1; i < grid.size(); i++) {
		for (int j = 1; j < grid[i].size(); j++) {
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
	cout << "Enter the size of the rows and columns: ";
	int n, m;
	cin >> n >> m;

	cout << "Enter the grid: " << '\n';
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int Minimum_Path_Sum = minPathSum(grid);

	cout << "Minimum Path sum is " << Minimum_Path_Sum << endl;
	return 0;
}