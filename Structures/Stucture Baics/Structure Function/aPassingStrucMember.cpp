#include<bits/stdc++.h>
using namespace std;
struct numbers
{
    int num;
}var;
void pass(int num)      // function to pass the structure member and print
{   
    cout<<"Passed number: "<<num<<endl;
}
int main()
{
      var.num=20;
      pass(var.num);    // passing structure member num
      return 0;
}