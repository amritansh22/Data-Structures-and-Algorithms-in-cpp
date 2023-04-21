#include <iostream>
using namespace std;

void tower(int num, char src, char aux, char dest)
{
    if (num == 1)
    {
        cout << "Move from " << src << " to " << dest << endl;
        return;
    }
    
    tower(num - 1, src, dest, aux); //Visualize how if we could move n-1 discs
    tower(1, src, aux, dest);       //we would move them to aux, then one disc to dest
    tower(num - 1, aux, src, dest); //then move the discs from aux to destination
}

int main()
{

    int n;
    cin >> n;

    tower(n, 'S', 'A', 'D');

    return 0;
}
