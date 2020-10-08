#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int>v;
    cout<<"Enter the number of digits : ";
    cin>>n;
    cout<<"Enter the digits: ";
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<int>v1;
    v1.push_back(1);
    for (int i = 1; i < n; i++ )
    {
        v1.push_back(1);
        for (int j = 0; j < i; j++ )
            if ( v[i] > v[j] && v1[i] < v1[j] + 1)
                v1.at(i) = v1[j] + 1;
    }
    make_heap(v1.begin(), v1.end());
    cout<<"The maximum length of the subsequence is : ";
    cout<<v1.front()<<endl;
}
