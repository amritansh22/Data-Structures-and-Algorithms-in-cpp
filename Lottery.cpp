#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "             Let's begin!                " << endl;
    while (true)
    {
        cout << "-----------------------------------------" << endl;
        cout << "|  Choose your lucky number             |" << endl;
        cout << "|  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10     |" << endl;
        cout << "-----------------------------------------" << endl;

        string input;
        cout << "Enter number: ";
        cin >> input;
        char number = input[0];
        cout << endl;
        int integerNumber = (int)number - 48;
        if (input == "10")
        {
            integerNumber = 10;
        }

        if ((input.length() >= 2 && (input != "10") ) || (integerNumber > 10) || (integerNumber < 0) || ((int)number < 48) || ((int)number > 57))
        {
            cout << "Oops! Your have entered invalid number." << endl;
        }
        else
        {
            int random = (rand() % 10) + 1;
            if (integerNumber == random)
            {
                cout << "*****************************" << endl;
                cout << ("* You are a lucky winner.   *") << endl;
                cout << "*****************************" << endl;

                while (true)
                {
                    cout << endl
                         << "Wannna, Play Again?" << endl;
                    cout << "To play again   Press: Y" << endl;
                    cout << "To exit         Press: N" << endl;
                    char playAgain;
                    cin >> playAgain;
                    if (toupper(playAgain) == 'Y' || toupper(playAgain) == 'N')
                    {
                        if (toupper(playAgain) == 'Y')
                        {
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Exiting from the programm..." << endl;
                            cout << "Exited." << endl;
                            return 0;
                        }
                    }
                    else
                    {
                        cout << "Oops! You have entered wrong choice." << endl;
                    }
                }
            }
            else
            {
                cout << ("=> You just missed it. Please try again.") << endl;
            }
        }
    }
    return 0;
}
