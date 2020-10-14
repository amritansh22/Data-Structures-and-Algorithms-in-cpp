/*Given a number A in a form of string.You have to find the smallest number that has same set of digits as A and is greater than A.
If A is the greatest possible number with its set of digits, then return -1.
Problem Constraints
1 <= A <= 10100000
A doesn't contain leading zeroes.
Input Format
First and only argument is an numeric string denoting the number A.
Output Format
Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.
Example Input
Input 1:
A = "218765"
Input 2:
A = "4321"
Example Output
Output 1:
"251678"
Output 2:
"-1"
 */
/*Approach: Check from back if it is in non increasing  sequence once we get the point that breaks the sequence
find a digit that is just next greater than the current digit and swap it. Sort the digits after the current digit*/
#include<bits/stdc++.h>
using namespace std;

string solve(string A) {
    int pt=A.length()-2;
    for(; pt>=0; pt--)
        if(A[pt]<A[pt+1])
            break;
    if(pt==-1)
        return "-1";
    sort(A.begin()+pt+1, A.end());
    int m = upper_bound(A.begin()+pt+1, A.end(), A[pt]) - A.begin();
    swap(A[pt], A[m]);
    
    return A;
}

int main(){
    string A = "218765";
    cout<<solve(A)<<endl;
    string B = "4321";
    cout<<solve(B)<<endl;
}
