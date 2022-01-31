//get ncr modulo m where m is prime

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N=100000,f[100000+5];
ll power(ll a,ll b,ll M)
{
    ll res=1;
    while(b)
    {
        if(b%2==1) res=res*a%M;
        b>>=1;
        a=a*a%M;
    }
    return res;
}

ll ncr(int n,int r,ll M)
{
    if(r>n) return 0;
    return f[n]*power(f[r],M-2,M)%M*power(f[n-r],M-2,M)%M;
}

int main()
{
    int n,r,i;
    ll M;
    cin>>n>>r;
    cin>>M;

    f[0]=1;
    for(i=1;i<=n;i++)
    f[i]=i*f[i-1]%M;
    cout<<ncr(n,r,M);
}
