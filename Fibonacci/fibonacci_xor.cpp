//Fibonacci XOR
/*You are given three integers a, b, and n, calculate f(n), where f(n) is the xor of last two numbers
i.e, f(n) = f(n-1)?f(n-2), where ? is xor operation.
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,n;
    
    cin>>a>>b>>n;
    int rem=n%3;
    if(rem==0) cout<<a<<endl;
    else if(rem==1) cout<<b<<endl;
    else cout<<(a^b)<<endl;
  
  return 0;
}
 