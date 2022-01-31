#include<bits/stdc++.h> 
using namespace std;

void leftRotate(int arr[], int d, int n) 
{ 
 
  d = d % n;                       //handle if d >=n
  int g_c_d = __gcd(d, n);        // __gcd predefine method in c++.which takes two input and return gcd.
  for (int i = 0; i < g_c_d; i++) { 
    int temp = arr[i];           // move i-th values of blocks
    int j = i; 

    while (1) { 
      int k = j + d; 
      if (k >= n) 
        k = k - n; 

      if (k == i) 
        break; 

      arr[j] = arr[k]; 
      j = k; 
    } 
    arr[j] = temp; 
  } 
} 


void printArray(int arr[], int size)   // Function to print an array 
{ 
  for (int i = 0; i < size; i++) 
    cout << arr[i] << " "; 
    cout<<endl;
} 

int main() 
{   
   int n,k;
   cout<<"Enter size of an array and value of k:\n";
   cin>>n>>k;
   int arr[n]; 
   for(int i=0; i<n; i++)
   {
    cin>>arr[i];
   }
  
  cout<<"Before Rotation:\n";
  printArray(arr, n); 

  leftRotate(arr,k, n);    // Function calling 

  cout<<"After Rotation:\n";
  printArray(arr, n); 


  return 0; 
    
}                                 //Time complexity: o(n) and space complexity:o(1)