#include<bits/stdc++.h>
#define M 1001
using namespace std;

int t[M][M];

int Count_Subset_Sum(vector<int> &arr, int sum, int n)
{
	//Initialization
	for(int i=0; i<M; i++)
	{
		t[0][i] = 0;
		t[i][0] = 1;
	}
	//Choice Diagram
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(arr[i-1]<=j)
				t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}

int main()
{
	int n,diff;
	cin>>n>>diff;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int arr_sum = 0;
	for(int i=0; i<n; i++)
		arr_sum += arr[i];
	int sum = (diff+arr_sum)/2;
	memset(t,0,sizeof(t));
	cout<<Count_Subset_Sum(arr,sum,n);
	return 0;
}
