/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(n).
Input Format :

Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :

Line 1 : Maximum value V

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :

4
1 2 4 5
5 4 8 6
5

Sample Output :

13

 */

#include<iostream>
using namespace std;


int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    
    //Let's have dp array which stores max profit at i for capacity i
    
    int dp[maxWeight+1]={0};
    
    for(int i=0;i<n;i++){
        
        for(int j=maxWeight;j>=weights[i];j--){
            
            dp[j]=max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    return dp[maxWeight];
    
    /* ******Recursive Solution for basic understanding************
    if(n==0 || maxWeights==0)
        return 0;
    
    if(weights[n-1]>maxWeights)
        return knapsack(weights,values, n-1,maxWeight);
    
    else
        return max(val[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1]),knapsack(weights,values,n-1,maxWeight));
    */

}




int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}


