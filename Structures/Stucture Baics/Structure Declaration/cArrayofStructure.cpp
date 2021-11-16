#include<bits/stdc++.h>
using namespace std;
struct pass
{
    int number;
}arr[3];
int main()
{
    int i ; // for iterating the loop
   // using for loop to initializing all arr member element
   cout<<"Enter Numbers to Initialize array structure members: "<<endl;
   for(i = 0; i<3; i++)
   {
      cin>>arr[i].number;
   }
   cout<<endl;
   cout<<"Printing all the structure array members: \n";
   for(i = 0; i<3; i++)
   {
      cout<<arr[i].number<<endl;
   }

    return 0;
}