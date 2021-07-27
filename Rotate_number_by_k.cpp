// Rotate digits of a number by K (number of shifts to be made in Number) 

#include <iostream>
using namespace std;


int main()
{
    cout<<"Enter the number:";
    string in;// input number is taken in form of string
    cin>>in;
  
    long long int n=in.length(); // stores the length of string number.
    cout<<"Enter the number of digits to be shifted:";
    long long int k;
    cin>>k;
  
    if(k>n) // incase when shifts is greater than the length of number
    {
        k=k%n;
    }
  
    string a=in.substr(0,k);
    string b=in.substr(k,n-k);
    string ans=b+a;
    cout<<"Final number is:"<<ans<<"\n";
  
    return 0;
}

