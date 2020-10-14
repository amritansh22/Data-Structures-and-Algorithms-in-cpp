#include <iostream>
#include<vector>
using namespace std;

typedef struct 
{
    int row=0;
    int col=0;
    int value=0;
}term;


int main()
{
    int matrix[100][100];
    term sparse[10];
    int n, m, i, j, k=0;
    cout<<"Enter the number of rows and columns of matrix: ";
    cin>>n>>m;
    cout<<"\nEnter the matrix: ";
    for(i=0; i<n;i++){
        for(j=0; j<m; j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                sparse[k].col= j;
                sparse[k].row = i;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }
    cout<<"The Sparse matrix is:"<<endl;
    cout<<"Row:\tColumn:\tValue:\n";
    for(i=0; i<k; i++){
        cout<<sparse[i].row<<"\t\t"<<sparse[i].col<<"\t\t"<<sparse[i].value<<endl;
    }
    return 0;
}
