// This method uses the technique of Sliding Window to arrive at the solution.
//
//Approach: This method efficiently implements the above Dynamic Programming approach.
//In this approach for the ith stair, we keep a window of sum of last m possible stairs from which we can climb to the ith stair. Instead of running an inner loop, we maintain the result of the inner loop in a temporary variable. We remove the elements of the previous window and add the element of the current window and update the sum.
//
//Below code implements the above idea

#include <iostream> 
using namespace std; 
  
// Returns number of ways 
// to reach s'th stair 
int countWays(int n, int m) 
{ 
    int res[n + 1]; 
    int temp = 0; 
    res[0] = 1; 
    for (int i = 1; i <= n; i++) 
    { 
        int s = i - m - 1; 
        int e = i - 1; 
        if (s >= 0) 
        { 
            temp -= res[s]; 
        } 
        temp += res[e]; 
        res[i] = temp; 
    } 
    return res[n]; 
} 
  
// Driver Code 
int main() 
{ 
    int n = 5, m = 3; 
    cout << "Number of ways = " 
         << countWays(n, m); 
    return 0; 
} 


//  
//output:
//	
//Number of ways = 13
//Complexity Analysis:

