#include<bits/stdc++.h>
using namespace std;

int largestArea(int n, int m , vector<int> a,vector <int>b)
{
  int end=0, start=0,i=0,j=0;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  while(i<n && j<m)
  {
    if(a[i] and b[i])
    {
      if(start==0)
        start=a[i];
      else
        end=a[i];
      i++;
      j++;
    }

    else if(a[i]>b[i])
      j++;
    else
      i++;
  }

  if(end==0 or start==0)
    return 0;
  else
    return(end-start);
}

int main()
{
  int t,n,m;
  vector<int> a;
  vector<int> b;
  cin>>t;
  scanf("%d %d", &n,&m);
  while(t--)
  {
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    for (int i = 1; i <= m; i++)
        b.push_back(i);
    int value=largestArea(n,m,a,b);
    cout<<value<<endl;
  }
  return 0;
}
