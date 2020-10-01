// N Queen's Problem
#include <iostream>
#define Q 4 //Q is globally declared here using macro
using namespace std;

bool check(int board[Q][Q],int row ,int col) ///this will check the attacks possible if any between the queens
{
    int i,j;
    for(i=0;i<col;i++)
    {
    if(board[row][i]) //this will prevent placement if another queen is in the same row
    return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--) //this will check if there is any queen already present in the upward left diagonal
    {
    if(board[i][j])
    return false;
    }
    for(i=row,j=col;j>=0 && i<Q ;i++,j--) //this will check if there is any queen already present in the lower left diagonal
    {
    if(board[i][j])
    return false;
    }
return true; //no attacks possible
}
bool placement(int board[Q][Q],int col)
{
if(col>=Q) //base condition it will stop the recursion if no of coloumns are equal to the no of queens
{
return true;
}
for(int i=0;i<Q;i++)  //we will try placement of queen for every row in each coloumn
{
    if(check(board,i,col)) //check if the queen is safe at that square
    {
    board[i][col]=1;
    if(placement(board,col+1)) //recursive call to place next queen in the next column
    return true;
    board[i][col]=0; // Backtracks if the placing of previous queen caused a problem in further placements
    }

}
return false;
}
void displayboard(int board[Q][Q])
{
for(int i=0;i<Q;i++)
{
    for(int j=0;j<Q;j++)
    cout<<board[i][j];
    cout<<endl;
}
}
bool solve()
{
int board[Q][Q] = {0};
if(placement(board,0)==false) //if queen cannot be placed at the first column
{
    cout<<"No possible solution"<<endl;
    return false;
}
displayboard(board);    //to print the board after all the queens are placed
return true;
}
int main()
{
solve();
return 0;
}
