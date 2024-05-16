// Hashing is a technique to find out the frequency of an element in an array at O(N) time complexity.
// This method uses hash array to perform hasing.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;   //size of array
    cin>>n;
    int max_input=INT_MIN;
    int nums[n];  //array to be hashed
    for(int i=0;i<n;i++){
        cin>>nums[i];
        max_input=max(max_input,nums[i]);
    }
    int hash[max_input+1]={0};
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    int desired_num;
    cin>>desired_num;
    cout<<"The frequency of "<<desired_num<<" is "<<hash[desired_num];
}
