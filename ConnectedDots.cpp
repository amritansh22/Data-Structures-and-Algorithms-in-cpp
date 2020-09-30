/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :

Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.

Output Format :

Return 1 if there is a cycle else return 0

Constraints :
2 ≤ N, M ≤ 50
Sample Input :

3 4
AAAA
ABCA
AAAA

Sample Output :

1

 */

void initialize(bool ** visited,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    }
}


bool dfs(char board[][MAXN],char col,int pi,int pj,int i,int j,int n,int m,bool **visited){
    
    //cout<<i<<" "<<j<<endl;
    
    bool d1=(i+1<n && !(i+1==pi && j==pj) && visited[i+1][j]);
    bool d2=(j+1<m && !(i==pi && j+1==pj) && visited[i][j+1]);
    bool d3=(i-1>=0 && !(i-1==pi && j==pj)&& visited[i-1][j]);
    bool d4=(j-1>=0 && !(i==pi && j-1==pj) && visited[i][j-1]);
    
    if(d1 || d2 || d3 || d4)
        return true;
    
    bool ans=false;
    visited[i][j]=true;
    if(i+1<n && board[i+1][j]==col && !visited[i+1][j])
        ans=ans || dfs(board,col,i,j,i+1,j,n,m,visited);
    
    if(j+1<m && board[i][j+1]==col && !visited[i][j+1])
        ans=ans || dfs(board,col,i,j,i,j+1,n,m,visited);
    
    if(i-1>=0 && board[i-1][j]==col && !visited[i-1][j])
        ans=ans || dfs(board,col,i,j,i-1,j,n,m,visited);
    
    if(j-1>=0 && board[i][j-1]==col && !visited[i][j-1])
        ans=ans || dfs(board,col,i,j,i,j-1,n,m,visited);
    
    return ans;
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
    }
    initialize(visited,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool ans=false;
            if(!visited[i][j]){
                char color=board[i][j];
                ans=dfs(board,color,i,j,i,j,n,m,visited);
                initialize(visited,n,m);
                //cout<<"======"<<endl;
                //cout<<endl;
                //cout<<ans<<endl;
                if(ans)
                    return 1;
            }
        }
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}