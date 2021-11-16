#include<bits/stdc++.h>
using namespace std;

//structure
struct details{
    long phnNo;
};

void myFun(struct details go);  // function prototype declaration

// main function
int main()
{
    struct details ph;
    ph.phnNo=1234567;
    myFun(ph); // passing entire structure to myFun function

    return 0;
}

void myFun(struct details go)
{
    cout<<" Phone Number: "<<go.phnNo; // printing phone number
}