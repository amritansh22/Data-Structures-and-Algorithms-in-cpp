#include <iostream>
using namespace std;
#include<map>
int main()
{   
    int n,i,j,sum,d,a,b;
    cin>>n;
    map<int,int>m;
    for(i=0;i<n-1;i++){
        cin>>d;
        m[i]=d;}
    cin>>a>>b;
    sum=0;
    for(j=a-1;j<b-1;j++){
        sum=sum+m[j];}
    cout<<sum;
}
