/* This program illustrates the implementation of the travelling salesman problem using dynamic programming*/
#include<iostream>
using namespace std;
#define INT_MAX 999999
int n;
int dist[10][10];
int VISITED;
int dp[16][4];
int  travelling_salesman(int mask,int pos){
    
    if(mask==VISITED){
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1){
       return dp[mask][pos];
    }
    int ans = INT_MAX;
    for(int city=0;city<n;city++){

        if((mask&(1<<city))==0){

            int tempAns = dist[pos][city] + travelling_salesman( mask|(1<<city), city);
            ans = min(ans, tempAns);
        }

    }
    return dp[mask][pos] = ans;
} 

int main(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin>>dist[i][j];
        }
    }
    VISITED = (1<<n) -1;
    for(int i = 0; i < (1<<n); ++i){
        for(int j = 0; j < n; ++j){
            dp[i][j] = -1;
        }
    }
    cout<<"Travelling Saleman Distance is "<<travelling_salesman(1,0);
return 0;
}
