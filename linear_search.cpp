//HEADER FILES
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void linearsearch(int arr[], int N,int K)
{
  int i;
  bool found = false;
  for(i=0;i<N;++i)
  {
    if(arr[i]==K)
    {
      found = true;
      break;
    }
  }
  if(found)
  cout<<K<<" found at index "<<i<<endl;
  else
  cout<<K<<" not found\n";
}

int main()
{
  int n,i,key;
  cout<<"Enter the number of elements in the array:- ";
  cin>>n;
  int a[n];
 
  cout<<"Enter "<<n<<" elements\n";
  for(i=0;i<n;++i)
  cin>>a[i];
     
  cout<<"Enter the element to be searched:- ";
  cin>>key;
  
  linearsearch(a,n,key);
  return 0; 
}
