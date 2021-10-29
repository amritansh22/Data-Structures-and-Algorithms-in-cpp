#include <iostream>
using namespace std;
int main()
{   int i,j,k,a,b,n,d,res,maximum;
    cin>>i;
    int e[i]={};
    for(j=0;j<i;j++)
    {   cin>>a;
        cin>>b;
        cin>>n;
        d=0;
        while(a<n||a==n)
        {   maximum=max(a,b);
            a=a+b; 
            b=maximum;
            d++;
        }
        e[j]=d;
        d=0;
    }
    for(k=0;k<i;k++)
    {cout<<e[k]<<"\n";}
}