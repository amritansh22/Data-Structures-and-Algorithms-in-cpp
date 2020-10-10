
#include <iostream>
#include <stdlib.h>
 using namespace std;
//algorithm to check whether the given number is a perfect number(i.e. sum of factors of the number equal to the number itself)
 int main()
 {
   int n;
   int sum=0;
 cout<<"enter the number you wan tot check"<<endl;
 cin>>n;
 for (int i=0 ; i<n ; i++)
 {
     if (n%i==0)
     {sum+=i;}
 }
   if(sum == n) 
   {cout<<"this number is a perfect number";} 

   else 
   {cout<<"not a perfect number";}  
     
     return 0;
 }