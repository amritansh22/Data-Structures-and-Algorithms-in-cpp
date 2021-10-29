#include <bits/stdc++.h>
 
using namespace std;
 
/* Iterative function to reverse
digits of num*/
int reversDigits(int num)
{
    // Handling negative numbers
    bool negativeFlag = false;
    if (num < 0)
    {
        negativeFlag = true;
        num = -num ;
    }
 
    int prev_rev_num = 0, rev_num = 0;
    while (num != 0)
    {
        int curr_digit = num % 10;
 
        rev_num = (rev_num * 10) + curr_digit;
 
        // checking if the reverse overflowed or not.
        // The values of (rev_num - curr_digit)/10 and
        // prev_rev_num must be same if there was no
        // problem.
        if ((rev_num - curr_digit) /
               10 != prev_rev_num)
        {
            cout << "WARNING OVERFLOWED!!!"
                 << endl;
            return 0;
        }
 
        prev_rev_num = rev_num;
        num = num / 10;
    }
 
    return (negativeFlag == true) ?
                         -rev_num : rev_num;
}
 
// Driver Code
int main()
{
    int num = 12345;
    cout << "Reverse of no. is "
         << reversDigits(num) << endl;
 
    num = 1000000045;
    cout << "Reverse of no. is "
         << reversDigits(num) << endl;
 
    return 0;
}
 
