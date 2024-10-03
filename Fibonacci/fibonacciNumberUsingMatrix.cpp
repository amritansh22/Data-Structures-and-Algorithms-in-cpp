// Program to find the nth fibonacci term

// what is fibonacci series?
// A series is said to be fibonacci if every nth term is the sum of (n-1)th and (n-2)th term. 0 1 1 2 3 5 8,..... is the fibonacci series

/*
According to this method, to get the nth fibonacci number, we need to multiply matrix [[1,1],[1,0]] to 
itself (n-1) times. Then, the [0,0]th element of this resultant matrix will be the required nth fibonacci number
*/

#include <cstdio>
#include<stdlib.h>
#include<iomanip>
#include<iostream>
using namespace std;

void multiply(int Fib[2][2], int mat[2][2])
{

    int topleft = Fib[0][0] * mat[0][0] + Fib[0][1] * mat[1][0];
    int topRight = Fib[0][0] * mat[0][1] + Fib[0][1] * mat[1][1];
    int bottomLeft = Fib[1][0] * mat[0][0] + Fib[1][1] * mat[1][0];
    int bottomRight = Fib[1][0] * mat[0][1] + Fib[1][1] * mat[1][1];
    
    Fib[0][0] = topleft;
    Fib[0][1] = topRight;
    Fib[1][0] = bottomLeft;
    Fib[1][1] = bottomRight;
}

void power(int Fib[2][2], int n)
{

	if(n == 0 || n == 1)
       return;
    int mat[2][2] = {{1, 1}, {1, 0}};
    
    power(Fib, n / 2);
    multiply(Fib, Fib);
    
    if (n % 2 != 0)
        multiply(Fib, mat);
}


int fibonacci(int n)
{
    int Fib[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(Fib, n - 1);

    return Fib[0][0];
}


int main()
{
	system("cls");
    int n;
    cout<<"Enter the nth fibonaci you want to know:  ";
    cin>>n;
    cout << fibonacci(n)<<endl;
    fflush(stdin);
    getchar();
    return 0;
}

