// C++ program to find n'th Super Ugly number 
#include<bits/stdc++.h> 
using namespace std; 
  
// Function to get the nth super ugly number 
// primes[]       --> given list of primes f size k 
// ugly           --> set which holds all super ugly 
//                    numbers from 1 to n 
// k              --> Size of prime[] 
int superUgly(int n, int primes[], int k) 
{ 
    // nextMultiple holds multiples of given primes 
    vector<int> nextMultiple(primes, primes+k); 
  
    // To store iterators of all primes 
    int multiple_Of[k]; 
    memset(multiple_Of, 0, sizeof(multiple_Of)); 
  
    // Create a set to store super ugly numbers and 
    // store first Super ugly number 
    set<int> ugly; 
    ugly.insert(1); 
  
    // loop until there are total n Super ugly numbers 
    // in set 
    while (ugly.size() != n) 
    { 
        // Find minimum element among all current 
        // multiples of given prime 
        int next_ugly_no = *min_element(nextMultiple.begin(), 
                                    nextMultiple.end()); 
  
        // insert this super ugly number in set 
        ugly.insert(next_ugly_no); 
  
        // loop to find current minimum is multiple 
        // of which prime 
        for (int j=0; j<k; j++) 
        { 
            if (next_ugly_no == nextMultiple[j]) 
            { 
                // increase iterator by one for next multiple 
                // of current prime 
                multiple_Of[j]++; 
  
                // this loop is similar to find  dp[++index[j]] 
                // it -->  dp[++index[j]] 
                set<int>::iterator it = ugly.begin(); 
                for (int i=1; i<=multiple_Of[j]; i++) 
                    it++; 
  
                nextMultiple[j] = primes[j] * (*it); 
                break; 
            } 
        } 
    } 
  
    // n'th super ugly number 
    set<int>::iterator it = ugly.end(); 
    it--; 
    return *it; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int primes[] = {2,  5}; 
    int k = sizeof(primes)/sizeof(primes[0]); 
    int n = 5; 
    cout << superUgly(n, primes, k); 
    return 0; 
} 
