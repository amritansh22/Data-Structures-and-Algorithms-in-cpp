#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;
int main()
{
    // set<int> s;
    set<int, greater<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    // for (auto i : s)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    //second method of printing in set
    // for (auto i = s.begin(); i != s.end(); i++)
    // {
    //     cout << *i << " \n";
    // }
    // reverse
    // for (auto i = s.rbegin(); i != s.rend(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;
    // size
    // cout << s.size() << "\n";

    //uppper and lower bound

    // cout << s.lower_bound(2) << endl;
    // cout << s.lower_bound(3) << endl;
    // cout << s.upper_bound(4) << endl;
    // cout << s.upper_bound(4) == s.end() << " \n";
    //erase will erase something what you want
    s.erase(1);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}