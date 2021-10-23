// C++ program to create calculator

#include <iostream>

using namespace std;


// Main program

int main()

{

    char oper;

    float a, b;

     // It allow user to enter the operands

    cout<<"Enter two operands: ";

    cin>> a >> b;

    // It allows user to enter operator i.e. +, -, *, /

    cout<<"Enter operator: ";

    cin>> oper;

    // Switch statement begins

    switch (oper)

    {

        // If operator is '+'

        case '+':

            cout << a + b;

            break;

        // If operator is '-'

        case '-':

            cout << a - b;

            break;

        // If operator is '*'

        case '*':

            cout << a * b;

            break;

        // If operator is '/'

        case '/':

            cout << a / b;

            break;

        // If any other operator display error message

        default:

            cout << "Error! Incorrect operator";

            break;

    }

    return 0;

}
