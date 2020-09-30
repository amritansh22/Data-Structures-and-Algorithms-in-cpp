#include <iostream>
using namespace std;

long fact(long n);

int nCr(long n, long r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
long fact(long n)
{
    long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
    long n, r;
    cout<<"Enter value of n:";
    cin>>n;
    cout<<"Enter value of r:";
    cin>>r;
    cout<<"Result nCr: "<<endl;
    cout<<nCr(n, r);
    return 0;
}
