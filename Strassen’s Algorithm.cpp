#include <iostream>
using namespace std;
void multiply(int[5][5], int[5][5], int, int, int);
int display(int[5][5], int, int);
int main()
{

   int a[5][5], b[5][5], r1, c1, r2, c2;
   cout<<"\n Enter rows for first matrix: ";
    cin>>r1;
   cout<<"\n Enter columns for second matrix: ";
     cin>>c1;

   cout<<"\n Enter rows for first matrix: ";
     cin>>r2;
   cout<<"\n Enter columns for second matrix: ";
      cin>>c2;

  // To check if columns of first matrix are equal to rows of second matrix

   if (c1 != r2)
        return 0;

   // Storing elements of first matrix.

   cout<<"\n Enter elements of first matrix \n";

   for(int i=0; i<r1; i++)
    {
       for(int j=0; j<c1; j++)
           cin>>a[i][j];

    }
   // Storing elements of second matrix.
    cout<<"\n Enter elements of second matrix\n";

   for(int i=0; i<r2; i++)
    {
       for(int j=0; j<c2; j++)
           cin>>b[i][j];
    }
    display(a,r1,c1);
    display(b,r2,c2);
    //calling the function to multiply a and b. passing number of rows
    //and columns in both of them
   multiply(a, b, r1, c2, c1);
   return 0;
}

void multiply(int a[5][5], int b[5][5], int row, int col, int c1)
{
   int c[5][5];
    //input 0 for all values of c, in order to remove
    //the garbage values assigned earlier
    for(int i=0; i<row; i++)
    {
       for(int j=0; j<col; j++)
           c[i][j]=0;
    }
    //we apply the same formula as above
   for(int i=0; i<row; i++)
    {
       for(int j=0; j<col; j++)
        {
           for(int k=0; k<c1; k++)//columns of first matrix || rows of second matrix
                  c[i][j]+=a[i][k]*b[k][j];
        }
    }
    //to display matrix
 cout<<"\n Matrix c after matrix multiplication is:\n";
  display(c, row, col);
}
int display(int c[5][5], int row, int col)
{
   cout<<"\n Matrix is:\n";
   for(int i=0; i<row; i++)
   {
       for(int j=0; j<col; j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}