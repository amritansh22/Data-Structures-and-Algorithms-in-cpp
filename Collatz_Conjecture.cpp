#include <bits/stdc++.h>
using namespace std;

/* Consider the following operation on an arbitrary positive integer n:
    If the number is even, divide it by two.
    If the number is odd, triple it and add one.
*/

int collatzConjecture(int n){
    int count = 0;
    while(n!=1){
        // if number is even, divide it by 2
        if(n%2==0){
            n=n/2;
        } else { // if odd, then multiply it by 3 and add 1
            n=3*n+1;
        }
        count++;
    }
    //returns the total steps count to make it 1
    return count;
}

int main()
{
    cout << collatzConjecture(276);

    return 0;
}
