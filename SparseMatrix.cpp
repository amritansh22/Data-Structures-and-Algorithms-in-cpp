//Program to convert a matrix to its sparse form

#include<iostream>
using namespace std; 


/**********************************************************
Format of Sparse Matrix:
Row
Column
Value
**********************************************************/

int main() 
{ 
  //Initialising the matrix
  int sparseMatrix[4][4] = 
  { 
    {9 , 0 , 7 , 0 }, 
    {0 , 1 , 0 , 7 }, 
    {0 , 1 , 5 , 0 }, 
    {0 , 0 , 0 , 0 } 
  }; 

  int size = 0; 
  for (int i = 0; i < 4; i++) 
    for (int j = 0; j < 4; j++) 
      if (sparseMatrix[i][j] != 0) 
        size++; 

  int arr[3][size]; 

  int k = 0; 
  for (int i = 0; i < 4; i++) 
    for (int j = 0; j < 4; j++) 
      if (sparseMatrix[i][j] != 0) 
      { 
        arr[0][k] = i; 
        arr[1][k] = j; 
        arr[2][k] = sparseMatrix[i][j]; 
        k++; 
      } 

  for (int i=0; i<3; i++) 
  { 
    for (int j=0; j<size; j++) 
      cout<< arr[i][j]; 

    cout<<endl; 
  } 
  return 0; 
} 


