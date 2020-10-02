#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int binarySearch(int a[],int x,int lo,int hi){
    int mid;
    while(hi>=lo){
        mid=lo+(hi-lo)/2;
        if(a[mid]==x)
            return mid+1;
        else if(a[mid]>x)
            hi=mid;         //always check binary search on two elements containing first false and second true.Whether loop never ends.
        else if(a[mid]<x)
            lo=mid+1;
    }
    return -1;
}

int main(){
    int n; cin>>n;
    int a[n]; for(int i=0;i<n;i++)  cin>>a[i];
    int x; cout<<"Enter the element to be searched"; cin>>x;
    cout<<binarySearch(a,x,0,n-1);
    return 0;
}
