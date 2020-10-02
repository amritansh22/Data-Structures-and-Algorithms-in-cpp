#include <iostream>
using namespace std;

int gcd(int n, int m){

    // Base cases
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    // Recursive cases
    if ((n&1)&(m&1))
        return (n >= m)? gcd((n-m)>>1, m) : gcd(n, (m-n)>>1);
    else if (n&1)
        return gcd(n, m>>1);
    else if (m&1)
        return gcd(n>>1, m);
    else
        return (gcd(n>>1, m>>1)<<1);
}

int main(){
    int n, m; cin >> n >> m;
    cout << gcd(n, m);
    return 0;
}
