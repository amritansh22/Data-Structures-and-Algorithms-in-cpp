#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    // s.erase(3);
    s.erase(s.find(3));
    for (auto i : s)
    {
        cout << i << endl;
    }

    return 0;
}