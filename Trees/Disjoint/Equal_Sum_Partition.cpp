#include<bits/stdc++.h>
#define M 1001 //Assuming the size of input
using namespace std;

int t[M][M];

bool Subset_Sum(vector<int> &arr, int sum, int n)
{
	//Initialization
	for(int i=0; i<M; i++)
	{
		t[0][i] = 0;
		t[i][0] = 1;
	}
	//Choice diagram
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(j>=arr[i-1])
				t[i][j] = t[i-1][j]||t[i-1][j-arr[i-1]];
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}

bool Equal_Sum_Partition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += arr[i];
	if(sum%2!=0)
		return 0;
	else
		return Subset_Sum(arr,sum/2,n);
}

int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	if(Equal_Sum_Partition(arr,n))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0; 
}
