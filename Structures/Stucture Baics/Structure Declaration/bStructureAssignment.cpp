#include<bits/stdc++.h>
using namespace std;
struct numbers{
    int a;
    int b;
}x, y;  // sturcture variable declaration can also be done this way
int main()
{
    x.a = 10;  // intializing structure member of x
    x.b = 20;

    y = x ;  // assigning one structure to another

    // printing y structure variable members

     cout<<"Structure y Members: "<<endl;
     cout<<"A = "<<y.a<<endl;
     cout<<"B = "<<y.b<<endl;
    return 0;
}
