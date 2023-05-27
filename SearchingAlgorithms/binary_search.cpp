#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
void bsearch(vector<int> a,int n,int key)
{
  sort(a.begin(),a.end());
  int start,end,mid;
  
  start = 0;
  end = n-1;
  bool found = false;
  while(start<=end)
  {
    mid = (start+end)/2;
    if(a[mid]==key)
    {
      found = true;
      break;
    }
    else
    if(a[mid]>key)
      end = mid-1;
    else
      start = mid+1;
  }
  if(found)
  cout<<key<<" found at index "<<mid<<endl;
  else
  cout<<key<<" not found\n";
}

int main()
{
  int n,k,i;
  
  vector<int>arr;
  cout<<"Enter elements, Q to stop \n";
  while(true){
    string element;
    cin >> element;
    if(element == "Q") break;
    arr.push_back(stoi(element));
  }   
  cout<<"Enter the element to be searched:- ";
  cin>>k;
  n = arr.size();
  bsearch(arr,n,k);
  return 0; 
}

