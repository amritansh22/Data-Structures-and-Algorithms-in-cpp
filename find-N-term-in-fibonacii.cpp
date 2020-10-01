#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==0 or n==1)
    {
        return n;
    }
    return f(n-1)+f(n-2);
}

int main()
{
    int n=6;
    cout<<f(n);
    
    return 0;
}
