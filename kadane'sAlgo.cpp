#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>& nums) {
        int max_sum=nums[0], sum=nums[0];
        for(int i=1; i<nums.size(); i++) {
            sum = max(nums[i], sum+nums[i]);
            if(sum>max_sum) {
                max_sum=sum;
            }
        }
        
        return max_sum;
    };
    
int main() 
{ 
    vector<int> a;
   for (int i = 1; i <= 10; i++) 
        a.push_back(i ); 
   int n = sizeof(a)/sizeof(a[0]); 
   int max_sum = maxSubArraySum(a); 
   cout << "Maximum contiguous sum is " << max_sum; 
   return 0; 
} 
