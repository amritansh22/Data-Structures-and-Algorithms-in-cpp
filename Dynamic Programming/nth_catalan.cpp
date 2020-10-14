/* This program illustrates the nth catalan number */
#include<iostream> 
using namespace std; 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
    unsigned long int res = 1; 
    if (k > n - k) 
        k = n - k; 
    for (int i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 
unsigned long int catalan(unsigned int n) 
{ 
    unsigned long int c = binomialCoeff(2*n, n);  
    return c/(n+1); 
} 
int main() 
{ 
    for (int i = 0; i < 10; i++) 
        cout << catalan(i) << " "; 
    return 0; 
} 
