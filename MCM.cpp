/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices i.e. determine where to place parentheses to minimise the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format :

Line 1 : Integer n i.e. number of matrices
Line 2 : n + 1 integers i.e. elements of array p[] 

Output Format :

Line 1 : Minimum number of multiplication needed

Constraints :

1 <= n <= 100

Sample Input 1 :

3
10 15 20 25

Sample Output :

8000

Sample Output Explanation :
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If multiply in order A1*(A2*A3) then number of multiplications required are 15000.
If multiply in order (A1*A2)*A3 then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000

 */

#include <bits/stdc++.h>
using namespace std;

int f(vector<vector <int> > &dp,int *p,int s,int e){
    if(e-s==1)
        return 0;
    
    if(dp[s][e])
        return dp[s][e];
    
    int ans=INT_MAX;
    for(int k=s+1;k<e;k++){
        int temp=f(dp,p,s,k)+f(dp,p,k,e)+p[s]*p[k]*p[e];
        ans=min(ans,temp);
    }
    dp[s][e]=ans;
    return ans;
}

int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    
    vector <vector <int> > dp(n+1,vector<int>(n+1,0));
    int ans=f(dp,p,0,n);
    return ans;
    
    
    


}

int main(){

  int n; 
  cin >> n;
  int* p = new int[n];

  for(int i = 0; i <= n; i++){
    cin >> p[i];
  }

  cout << mcm(p, n);

}