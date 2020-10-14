//Rotate matrix by 90 degree
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j,matrix[n][n];
    for(int i=0;i<n;i++)
        for(int j=0l;j<n;j++)
            cin>>matrix[i][j];
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        int k;
        for(k=0;k<n;k++)
        {
            i=0,j=n-1;
            while(j>i)
            {
                swap(matrix[k][i],matrix[k][j]);
                i++;
                j--;
            }
        }
    return 0;
}
