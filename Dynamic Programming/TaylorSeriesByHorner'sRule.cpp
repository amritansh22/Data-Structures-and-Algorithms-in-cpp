// To calculate value of Taylor series by using Horner's Rule
#include <iostream>
using namespace std;

double e(int x, int n)
{
    static double s;
    if (n==0)
        return s;
    s = 1 + x*s/n;
    return e(x, n-1);
}

int main ()
{
    cout<<e(4, 15);

    return 0;
}
