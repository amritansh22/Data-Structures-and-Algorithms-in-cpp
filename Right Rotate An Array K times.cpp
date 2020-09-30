#include<bits/stdc++.h> 
using namespace std; 
  
// Function to rightRotate array 
void RightRotate(int a[], int n, int k) 
{ 
      
    // If rotation is greater  
    // than size of array 
    k = k % n; 
  
    for(int i = 0; i < n; i++) 
    { 
       if(i < k) 
       { 
             
           // Printing rightmost  
           // kth elements 
           cout << a[n + i - k] << " "; 
       } 
       else
       { 
             
           // Prints array after 
           // 'k' elements 
           cout << (a[i - k]) << " "; 
       } 
    } 
    cout << "\n"; 
} 

int main() 
{ 
    int N,K,i;
    //input number of elements in array
    cin>>N; 
    
    int arr[N];
    for(i=0;i<N;i++)
    {
      cin>>arr[i];
    }
    
    //number of times to rotate an array
    cin>>K;
     
    RightRotate(arr, N, K); 
} 
