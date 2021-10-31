#include <iostream>
#include <cstring>

using namespace std;
string reverse(string& rev)
{
    int n = rev.length();
    for (int i = 0; i < n / 2; i++)
        swap(rev[i], rev[n - i - 1]);
    return rev;
}
int main()
{
    string str,rev;
    cout<<"Enter String :";
    cin>>str;
    rev=str;
    cout<<"String details\nLength : "<<str.length()<<"\nReverse : "<<reverse(rev)<<"\nPaliandrome : ";
    if(str.compare(rev) == 0)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }

    return 0;
}
