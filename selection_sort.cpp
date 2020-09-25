#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector <int> &arr)  
{  
    int i, j, min_idx; 
    int n=arr.size();
    for (i = 0; i < n-1; i++)  
    {   
        min_idx = i;  
        for (j = i+1; j < n; j++)  
            if (arr[j] < arr[min_idx])  
                min_idx = j;  
        swap(arr[min_idx], arr[i]);  
    }  
}

int main() {
  int n;
  cin>>n;
  vector <int> arr(n);
  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }
  selectionSort(arr);
  
  for(int i=0;i<n;i++) {
    cout<<arr[i]<<" ";
  }
  
  return 0;
}
