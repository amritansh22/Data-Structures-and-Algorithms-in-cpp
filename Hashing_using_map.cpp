#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;   //size of array
    cin>>n;
    int nums[n];  //array to be hashed
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    map<int,int> hashmap;
    for(int i=0;i<n;i++){
    hashmap[nums[i]]++;
    }
    int desired_num;
    cin>>desired_num;
    cout<<"The frequency of "<<desired_num<<" is "<<hashmap[desired_num];
}


