#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char fr, char tr, char ar)
{
	if (n == 1)
	{
		cout << "Move disk 1 from rod " << fr <<" to rod " << tr<<"\n";
		return;
	}
	towerOfHanoi(n - 1, fr, ar, tr);
	cout << "Move disk " << n << " from rod " << fr <<" to rod " << tr << "\n";
	towerOfHanoi(n - 1, ar, tr, fr);
}

int main()
{
	int n;
    cin>>n;
	towerOfHanoi(n, 'A', 'C', 'B'); 
	return 0;
}
