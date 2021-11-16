#include<bits/stdc++.h>
using namespace std;

// stducture Declaration

struct studentDetails   // struct is used to define a stucture
{                       // studentDetails is structure type
  int roll;
  string name;                    // structure memebers
  int age;       
  
};
int main()
{
    struct studentDetails stud; // structure variable declaration
    stud.age=22;
    stud.name="Mimo Patra";       // accessing structure member using structure variable
    stud.roll=153;

    // printing structure members

    cout<<" Structure Mmbers: "<<endl;
    cout<<"Name = "<<stud.name<<endl;
    cout<<"Roll = "<<stud.roll<<endl;
    cout<<"Age = "<<stud.age<<endl;
   return 0;
}