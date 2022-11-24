
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int num){
    
       long long int beg=0,end=num;
       long long int mid=beg+(end-beg)/2;
       long long int ans=-1;
       
        while(beg<=end){
            
        if(mid*mid==num)
            return mid;
            
        else if(mid*mid<num){
            ans=mid;
            beg=mid+1;
        }
        
        else
            end=mid-1;
            
        mid=beg+(end-beg)/2;
        }
        
        return ans;
}

//Code by [Puneetpoter](https://github.com/Puneetpotter)

int main() {
    long long int x;
    cin>>x;
    printf("The square root of %d calculated using binarySearch function is : ",x); 
    cout<<binarySearch(x);

    return 0;
}