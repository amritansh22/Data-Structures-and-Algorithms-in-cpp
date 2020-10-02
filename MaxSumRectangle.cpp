/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input

First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.

Output

Output a single integer, maximum sum rectangle.

Constraints

1<=n,m<=100

Sample Input

4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

Sample Output

29
 */


#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    
    int all_neg=1;
    
    //Loop to check for all negatives;
    
    int neg_max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            all_neg=0;
            break;
        }
        neg_max=max(neg_max,arr[i]);
        
    }
    if(all_neg)
        return neg_max;
        
    int maxsum=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0)
            sum=0;
        maxsum=max(sum,maxsum);
    }
    return maxsum;
    
}


int main()
{
    int n,m;
    cin>>n>>m;
    
    int a[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int ans=INT_MIN;
    int v[n]={0};
    // The Approach is to have vertical sliding window and within that window try to find max contigos
    for(int i=0;i<m;i++){
        
        for(int j=i;j<m;j++){
            
            for(int k=0;k<n;k++)
                v[k]+=a[k][j];
            int t=kadane(v,n);
            ans=max(t,ans);
            
        }
        fill_n(v,n,0);
    }
    cout<<ans<<endl;
    
    return 0;
}
