#include<iostream>
using namespace std;
void fib(int a,int b,int n)
{
	if (n==0)
	{
		return;
	}int c= a+b;
	cout<<c<<endl;
	fib(b,c,n-1);
}int main()
{
	int a=0,b=1;
	int n;
	cout<<"ENTER THE VALUE OF N-";
	cin>>n;
	cout<<a<<endl;
	cout<<b<<endl;
	fib(0,1,n);
}
