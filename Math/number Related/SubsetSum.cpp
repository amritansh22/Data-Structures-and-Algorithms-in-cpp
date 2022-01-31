
/* A Dynamic Programming solution for subset,
This code solves the problem in 
Pseudo-polynomial time use the Dynamic programming.


*/
#include<iostream>
using namespace std;
  
   
    bool isSubsetSum(int set[],int n, int sum) 
    { 
      
        bool subset[sum + 1][n + 1]; 
  
        for (int i = 0; i <= n; i++) 
            subset[0][i] = true; 
  
    
        for (int i = 1; i <= sum; i++) 
            subset[i][0] = false; 
  
    
        for (int i = 1; i <= sum; i++) { 
            for (int j = 1; j <= n; j++) { 
                subset[i][j] = subset[i][j - 1]; 
                if (i >= set[j - 1]) 
                    subset[i][j] = subset[i][j] || subset[i - set[j - 1]][j - 1]; 
            } 
        } 
  
        return subset[sum][n]; 
    } 
  
    /* Driver code */
    int main() 
    {
cout<<"Enter the size of your array:";
        int n; 
        cin>>n;

        int set[n];
        
        cout<<"Enter your array:";
        for (int i = 0; i < n; i++)
         cin>>set[i]; 

        cout<<"Enter the sum:";
        int sum; 
        cin>>sum;
        
        if (isSubsetSum(set, n, sum) == true) 
           {cout<<"Found a subset"<<" with given sum"<<endl;
            } else{
            cout<<"No subset with"<<" given sum"<<endl;
            }

      return 0;   
    } 

  