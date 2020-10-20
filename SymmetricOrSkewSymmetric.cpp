#include <iostream>
using namespace std;

int main()

{
	int n;

	cout << "Enter size of square matrix\n"; //inputting size of the matrix

	cin >> n;

	int a[n][n];

	cout << "Enter the matrix row-wise\n";	//inputting the matrix row wise

	for (int i = 0; i < n; ++i)

	{
		for (int j = 0; j < n; ++j)

		{

			cin >> a[i][j];
		}
	}

	int ctr = 1;

	for (int i = 0; i < n; ++i)	//check for symmetric matrix

	{
		for (int j = 0; j < n; ++j)

		{

			if (a[i][j] != -a[j][i])

			{

				ctr = 0;

				break;
			}
		}

		if (ctr == 0)

			break;
	}

	if (ctr)	//printing if matrix is symmetric

		cout << "Matrix is skew-symmetric\n";

	else	//checking if skew symmetric matrix

	{
		ctr = 1;

		for (int i = 0; i < n; ++i)

		{

			for (int j = 0; j < n; ++j)

			{

				if (a[i][j] != (-a[j][i]))

				{

					ctr = 0;

					break;
				}
			}

			if (ctr == 0)

				break;
		}

		if (ctr)	//printing if matrix is skew symmetric matrix

			cout << "Matrix is skew-symmetric\n";

		else	//if not then its neither of the two

			cout << "Matrix is neither symmetric nor skew-symmetric\n";
	}

	return 0;

}
