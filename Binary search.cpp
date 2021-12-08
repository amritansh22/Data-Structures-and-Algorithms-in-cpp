#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n; //size of array
    cin>>n;
    int ar[n]; //to store the elements of the array
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    //  the array inputed should either be sorted or we may sort it
    sort(ar,ar+n); //considering the array is not sorted
    int x; //to store the number to check if present in the array or not
    cin>>x;
    //binary search technique
    int lo=0, hi=n-1;
    int mid;
    int pos=-1;
    while(lo <= hi)
    {
      mid=(lo+hi)/2;
      if(ar[mid]==x) //if the element is present in the middle of the current subarray
      {
        pos=mid;
        break;
      }
      else if(ar[mid]<x) //if the element is smaller than the element at mid then it is present in left subarray
      {
          lo=mid+1;
      }
      else { //if the element is greater than the element at mid it can only be present in the right subarray
        hi=mid-1;
      }
    }
    if(pos==-1){
        cout<<"The element is not present";
    }
    else{
        cout<<"The element is present";
    }

}
