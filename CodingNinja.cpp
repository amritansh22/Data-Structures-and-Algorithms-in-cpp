/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :

Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on

Assume input to be 0-indexed based
Output Format :

Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.

Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :

2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output :

1

 */


void initialize(bool **visited,int N,int M){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}


bool dfs(char Graph[][MAXN],char c[],int i,int j,int N,int M,bool ** visited){
    
    if(Graph[i][j]=='A')
        return true;
    
    visited[i][j]=true;
    bool ans=false;
    
    if(i-1>=0 && j-1>=0 && Graph[i-1][j-1]==c[0] && !visited[i-1][j-1])
        ans=ans || dfs(Graph,c+1,i-1,j-1,N,M,visited);
    
    if(i-1>=0 && Graph[i-1][j]==c[0] && !visited[i-1][j])
        ans=ans || dfs(Graph,c+1,i-1,j,N,M,visited);
    
    if(i-1>=0 && j+1<M && Graph[i-1][j+1]==c[0] && !visited[i-1][j+1])
        ans=ans || dfs(Graph,c+1,i-1,j+1,N,M,visited);
    
    if(j+1<M && Graph[i][j+1]==c[0] && !visited[i][j+1])
        ans=ans || dfs(Graph,c+1,i,j+1,N,M,visited);
    
    if(i+1<N && j+1<M && Graph[i+1][j+1]==c[0] && !visited[i+1][j+1])
        ans=ans || dfs(Graph,c+1,i+1,j+1,N,M,visited);
    
    if(i+1<N && Graph[i+1][j]==c[0] && !visited[i+1][j])
        ans=ans || dfs(Graph,c+1,i+1,j,N,M,visited);
    
    if(i+1<N && j-1>=0 && Graph[i+1][j-1]==c[0] && !visited[i+1][j-1])
        ans=ans || dfs(Graph,c+1,i+1,j-1,N,M,visited);
    
    if(j-1>=0 && Graph[i][j-1]==c[0] && !visited[i][j-1])
        ans=ans || dfs(Graph,c+1,i,j-1,N,M,visited);
    
    return ans;
    
    
    
    
    
}

int solve(char Graph[][MAXN],int N, int M)
{
	// Write your code here.
    char c[]="CODINGNINJA";
    bool **visited=new bool*[N];
    for(int i=0;i<N;i++){
        visited[i]=new bool[M];
    }
    
    initialize(visited,N,M);
    for(int i=0;i<N;i++){
        
        for(int j=0;j<M;j++){
            bool ans=false;
            if(Graph[i][j]=='C'){
                ans=dfs(Graph,c+1,i,j,N,M,visited);
                if(ans)
                    return 1;
                
                initialize(visited,N,M);
                
            }
        }
    }
    
    return 0;
    
}



#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}