#include<bits/stdc++.h>
using namespace std;

void bsearch(int a[],int n,int key)
{
  sort(a,a+n);
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
  cout<<"Enter the number of elements in the array:- ";
  cin>>n;
  int arr[n];
 
  cout<<"Enter "<<n<<" elements\n";
  for(i=0;i<n;++i)
  cin>>arr[i];
     
  cout<<"Enter the element to be searched:- ";
  cin>>k;
  
  bsearch(arr,n,k);
  return 0; 
}

