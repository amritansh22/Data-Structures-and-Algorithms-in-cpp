//Program to multiply multiple user defined matrices

#include <iostream>
#include <string.h>
using namespace std;

void input(int matrix[][10], int row, int column) {

   cout<<"\nEnter elements: \n";

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cin>>matrix[i][j];
      }
   }
}


void multiply(int first[][10],int second[][10],int result[][10],int r1, int c1, int r2, int c2) {

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

void display(int result[][10], int row, int column) {

   cout<<"\nOutput Matrix:\n";
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cout<<result[i][j]<<" ";
         if (j == column - 1)
            cout<<"\n";
      }
   }
}

int main() {
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
      
   int nm;
   cout<<"Enter number of matrices you want to multiply: \n";
   cin>>nm;

   cout<<"Enter no. of rows and column for the first matrix: ";
   cin>>r1>>c1;
   input(first, r1, c1);

   while(--nm>0){
         cout<<"Enter no. of rows and column for the next matrix: ";
         cin>>r2>>c2;
            if (c1 != r2) {
            cout<<"\nNo. of Columns of first matrix not equal to no. of rows of second matrix!!";
            return 0;
            }
      input(second, r2, c2);
      multiply(first, second, result, r1, c1, r2, c2);
      r1=r1;
      c1=c2;
      memcpy(first, result, 100);
   }

   display(result, r1, c2);
   return 0;
}