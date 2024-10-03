//Question: - You are given weights and values of N items,
//put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
//Note that we have only one quantity of each item.

//Dynamic Programming - 0/1 Knapsack

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int w;
	    cin>>w;
	    int val[n],wt[n],i,j;
	    for(i=0;i<n;i++)
	        cin>>val[i];
	     for(i=0;i<n;i++)
	        cin>>wt[i];
	   int dp[n+1][w+1];
	  
	  for(i=0;i<=n;i++)
	    for(j=0;j<=w;j++)
	       { if(i==0||j==0)
	            dp[i][j]=0;
	       else
	        {if(wt[i-1]>j)
	            dp[i][j]=dp[i-1][j];
	        else
	            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
	        }
	       }
	   
	   cout<<dp[n][w]<<endl;
	}
	return 0;
}
