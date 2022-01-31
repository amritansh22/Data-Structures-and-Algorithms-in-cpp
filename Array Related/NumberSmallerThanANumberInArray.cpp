#include <iostream>
#include <string.h>
using namespace std;
int main()
{
int n;
cout << "Enter the size of array" << endl;
cin >> n;
int a[n];
cout << "enter the array elements" << endl;
for(int i=0;i<n;i++0
{
cin >> a[i];
}
int k;
cin >> k;
int count = 0;
for(int i=0;i<n;i++0
{
if(a[i]<k)
{
count++;
}
}
cout << "numbers smaller tha entered number in array is" << endl;
cout << count << endl;

return 0;
}
