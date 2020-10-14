#include <iostream>
using namespace std;
int countSetBits(int x)
{
	int count = 0;
	while (x)
	{
		x &= (x - 1);
		count++;
	}
	return count;
}
int main()
{
	int n, x, y = 1;
	cout << "Enter a number: ";
	cin >> n;
	while (n)
	{
		for (x = 1; x < n; x++)
		{
			if ((x + countSetBits(x) == n))
			{
				cout << "No, its not a bleak number.";
				cout << "\n"
					 << n << " = " << x << " + countSetBits(" << x << ")";
				return 0;
			}
		}
		cout << "Yes, its a bleak number.";
		return 1;
	}
}
