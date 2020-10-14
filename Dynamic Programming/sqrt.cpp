//Find square root of a number without sqrt operation
#include<bits/stdc++.h>
using namespace std;
int Sqrt(int x) {
    if(x<=1)
        return x;
    long long start=1,end=x;
    while(start<=end)
    {
        long long mid=start+(end-start)/2;
        if(mid==x/mid)
            return mid;
        if(mid<x/mid)
            start=mid+1;
        else if(mid>x/mid)
            end=mid-1;
    }
        return (int)end;
    }
int main()
{
    int x;
    cin>>x;
    cout<<Sqrt(x);
    return 0;
}
