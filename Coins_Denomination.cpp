#include<bits/stdc++.h>
#define M 1001  //Asssuming the input size
using namespace std;

int t[M][M]; //This is the topdown matrix 

int min(int a, int b)
{
	return (a>b?b:a); 
}

int Min_NUM_Of_Coins(vector<int> &coins, int sum, int n)
{
	//Initialization
	//First Row and first column
	for(int i=0; i<M; i++)
	{
		t[i][0] = 0;
		t[0][i] = INT_MAX-1;
	}
	//Second row 
	for(int i=1; i<sum+1; i++)
	{
		if(i%coins[0]==0)
			t[1][i]=i/coins[0];
		else
			t[1][i]=INT_MAX-1;
	}
	//Choice Diagram
	for(int i=2; i<n+1; i++)
	{
		for(int j=1; j<sum+1; j++)
		{
			if(j>=coins[i-1])
				t[i][j] = min((t[i][j-coins[i-1]]+1),t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][sum];
}

int main()
{
	int n,sum;
	cin>>n>>sum;
	vector<int> coins(n);
	for(int i=0; i<n; i++)
		cin>>coins[i];
	memset(t,0,sizeof(t));
	cout<<Min_NUM_Of_Coins(coins,sum,n)<<endl;
	return 0;
}
