//using dp
#include<iostream>
using namespace std;
int permutation(int n,int r)
{
    int p=1;
    for (int i = 0; i < r; i++) 
        p *= (n-i) ; 
    
    return p;
}
int main()
{
    int n,r;
    cout<<"\n The permutaion coefficient of Per("<<n<<","<<r<<") is : "<<permutation(n,r);
    return 0;
}