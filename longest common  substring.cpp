#include<bits/stdc++.h>
using namespace std;
int fun(string a,string b,int n,int m)
{
    int ss[n+1][m+1];
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            ss[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                ss[i][j]=ss[i-1][j-1]+1;
                ans=max(ss[i][j],ans);
            }
            else
            ss[i][j]=0;
        }
    }
    return ans;
}
int main()
 {
  //code
  int t;
  cin>>t;
  while(t--)
  {
      int n,m;
      cin>>n>>m;
      string a,b;
      cin>>a;
      cin>>b;
      cout<<fun(a,b,n,m)<<endl;
  }
  return 0;
}
