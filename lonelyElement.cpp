/*Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

#include<iostream>
#include<vector>
using namespace std; 

// Optimised approach O(N) time O(1) space
int singleNumber(vector<int>& nums) {
        /*
        This solution is predefined on the fact that 
        every element which is equal to each other will have an XOR = 0 
        so if we take the XOR of all the elements all the elements will pair up and 
        the Xor value will be the single integer value which is remaining. 
        */
        int x =0 ;                       
        for(int i=0 ;i<nums.size(); i++){
            x ^= nums[i]; 
        }
        
        return x;
}

// O(N) Time O(N) Space Complexity
int singleNumberUsingMap(vector<int>& nums){
    /*
    In this solution we take advantage of the fact that that the array contains all duplicate 
    elements and only one element is of freq 1 
    We will traverse through the array and see if the particular element is occuring once in the array and we do not have that 
    element in the map then we will add that element to the map and if we have that element in the map then we will erase that element. 
    If we do this thing for the entire array we will end up with only one element in end and that will be the lonely element in the array. 
    */

    unordered_map<int,int> m ; 
    for(int i=0 ;i<nums.size(); i++){
        if(m.find(nums[i])!=m.end()){
            m.erase(nums[i]);
        }else{
            m[nums[i]]++; 
        }
    }

    return m[0].first; 
}


int main(){
    int n; 
    cin >> n ;
    vector<int> v ;
    for(int i=0 ;i<n ;i++){
        int x ;
        cin >> x ;
        v.push_back(x); 
    }

    int ans = singleNumber(v); 
    int ans1 = singleNumberUsingMap(v); 
    cout << ans<< endl ;
    cout << ans1 << endl; 
    return 0 ;
}