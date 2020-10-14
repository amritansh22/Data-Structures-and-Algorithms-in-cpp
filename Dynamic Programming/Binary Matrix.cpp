#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    string s[n],s1[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        s1[i]=s[i];
    }
    sort(s,s+n,greater<string>());
    string temp=s[0];
    for(int i=0;i<n;i++)
    {
        if(s1[i]==temp)
        {cout<<i+1<<endl;
            break;
        }
    }
    
    
}
