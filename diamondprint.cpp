#include<iostream>

main() {
   int n, i, j, space=1;
   cout<<"Enter number of rows : ";
   cin>>n;
   space=n-1;
   for (i=1; i<=n; i++) {
      for(j=1; j<=space; j++) {
         cout<<" "; //print space.
      }
      space--;
      for(j=1; j<=(2*i-1); j++) {
         cout<<"*"; //print stars.
      }
      cout<<"\n";
   }
   //in reverse order.
   space=1;
   for (i=1; i<=n; i++) {
      for(j=1; j<=space; j++) {
         cout<<" "; //print space.
      }
      space++;
      for(j=1; j<=(2*(n-i)-1); j++) {
         cout<<"*"; //print stars.
      }
      cout<<"\n";
   }
}
