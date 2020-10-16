/* 
   Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.
   If there is no non-empty subarray with sum at least K, return -1.
    
   Input: A = [2,-1,2], K = 3
   Output: 3

*/


#include<bits/stdc++.h>

using namespace std;

int shortestSubarray(vector<int>& A, int K) 
{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;   // min heap to store the length and sum of the subarray
        int sum = 0;
        int ans = INT_MAX;
        for(int i=0;i<A.size();i++){
            sum += A[i];
            if(sum >= K){
                ans = min(ans,i+1);
            }
            while(pq.size() >0 && sum-pq.top().first >=K ){
                ans = min(ans,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans == INT_MAX ? -1 : ans;
}

int main()
{
      int K;
      cin >> K;
      cout << "Enter the number of elements in the array" ; 
      int n;
      cin >> n;
      vector<int> arr(n);
      for(int i=0;i<n;i++)
      {
          int x;
          cin >> x;
          arr.push_back(x);
      }
      
      cout << shortestSubarray(arr , K);
      
      return 0;
}




 
