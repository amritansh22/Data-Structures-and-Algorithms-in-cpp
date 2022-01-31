/* Program to find longest subarray with zero sum in an array of positive and negative integers /*

#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}



int maxLen(int A[], int n)
{   unordered_map<int,int> a;
int s=0,m=0;
a[0]=-1;
    for(int i=0;i<n;++i)
    {
        s+=A[i];
        auto y=a.find(s);
        if(y==a.end())
        a[s]=i;
        else
        {
            if(i-a[s]>m)
            m=i-a[s];
            
        }
        
        
    }
    return m;
}
