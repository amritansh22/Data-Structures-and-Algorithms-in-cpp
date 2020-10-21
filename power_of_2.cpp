/* Program to check whether a given number is a power of 2 using bit-magic /*


#include <iostream>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    long long int n;
    cin>>n;
    if(n==0)
    cout<<"NO";
    else if((n&(-n))==n)
    cout<<"YES";
    else
    cout<<"NO";
    
    cout<<'\n';  
    
    
    
    
    
    
}
	return 0;
}
