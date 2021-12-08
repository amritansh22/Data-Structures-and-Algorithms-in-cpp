/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :

Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake

Output Format :

Size of the biggest piece of '1's and no '0's

Sample Input :

2
11
01

Sample Output :

3

 */

void dfs(char cake[NMAX][NMAX],int n,int &k,int i,int j){
    k++;
    cake[i][j]='0';
    
    if(i+1<n && cake[i+1][j]=='1')
        dfs(cake,n,k,i+1,j);
    if(i-1>=0 && cake[i-1][j]=='1')
        dfs(cake,n,k,i-1,j);
    if(j+1<n && cake[i][j+1]=='1')
        dfs(cake,n,k,i,j+1);
    if(j-1>=0 && cake[i][j-1]=='1')
        dfs(cake,n,k,i,j-1);
    
}

int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(cake[i][j]=='1'){
                int k1=0;
                dfs(cake,n,k1,i,j);
                ans=max(ans,k1);
            }
        }
    }
    return ans;
}


#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}