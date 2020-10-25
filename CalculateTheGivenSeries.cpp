//C++ program to find the sum of the series (1)+(1+2)+(1+2+3)+(1+2+3+...+n)

#include <iostream>

using namespace std;

int main()

{

  int i, j, n, sum, total = 0;

  cout << "Enter the value for nth term: ";

  cin >> n;

  for (i = 1; i <= n; i++)

  {

    sum = 0;

    for (j = 1; j <= i; j++)

    {

      total += j;

      sum += j;

      cout << j;

      if (j < i)

      {

        cout << "+";

      }

    }

    cout << " = " << sum << endl;

  }

  cout << "\nThe sum of the above series is: " << total << endl;

}