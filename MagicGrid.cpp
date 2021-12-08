/*
You are given a magrid S ( a magic grid ) having R rows and C columns. Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion that his teacher Snape has left for him. A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j]. If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.
Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C). From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid. Harry has used magic before starting his journey to determine which cell contains what, but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.
Input (STDIN)

The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with S[i][j] < 0 contain dragons, others contain magic potions.

Output (STDOUT):

Output T lines, one for each case containing the minimum strength Harry should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).

Constraints:

1 ≤ T ≤ 5

2 ≤ R, C ≤ 500

-10^3 ≤ S[i][j] ≤ 10^3

S[1][1] = S[R][C] = 0

Sample Input

3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0

Sample Output

2
1
2
 */


#include <bits/stdc++.h>
using namespace std;
/*
int mg(vector <vector <int> > &dp,vector <vector <int> > &a,int i,int j,int ei,int ej){
    
    if(i==ei && j==ej)
        return 1;
    
    if(dp[i][j])
        return dp[i][j];
    
    int ans1=INT_MAX;
    int ans2=INT_MAX;
    int ans=INT_MAX;
    if (i+1<ei)
        ans1=mg(dp,a,i+1,j,ei,ej)-a[i+1][j];
    if(j+1<ej)
        ans2=mg(dp,a,i,j+1,ei,ej)-a[i][j+1];
    
    ans=min(ans1,ans2);
    dp[i][j]=ans;
    return ans;
}
*/

int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int R,C;
        cin>>R>>C;
        vector <vector <int> > a(R,vector<int>(C));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++)
                cin>>a[i][j];
        }
        
        vector <vector <int> > dp(R,vector<int>(C,0));
        
        //Initialization
        dp[R-1][C-1]=1;
        
        for(int i=R-2;i>=0;i--)
            dp[i][C-1]=dp[i+1][C-1]-a[i+1][C-1];
        
        for(int j=C-2;j>=0;j--)
            dp[R-1][j]=dp[R-1][j+1]-a[R-1][j+1];
        
        for(int i=R-2;i>=0;i--){
            for(int j=C-2;j>=0;j--){
                dp[i][j]=min(dp[i+1][j]-a[i+1][j],dp[i][j+1]-a[i][j+1]);
                
                if(dp[i][j]<=0)
                    dp[i][j]=1;
            }
        }
        
        /*
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        */
        cout<<dp[0][0]<<endl;
        /*
        if(ans<=0)
            cout<<1<<endl;
        else
            cout<<ans<<endl; 
        */
        
    }
    return 0;
}
