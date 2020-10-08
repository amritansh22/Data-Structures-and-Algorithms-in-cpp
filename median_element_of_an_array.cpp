#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    float med=0;
    cout<<"Enter the number of elements in array : ";
    cin>>n;
    cout<<"Enter the elements : ";
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(i==n/2||i==n/2-1)
            {
                med=med+a;
            }
        }
        cout<<"The median is : "<<med/2<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(i==n/2)
        {
            cout<<"The median is: "<<a<<endl;
            return 0;
        }
    }
}
