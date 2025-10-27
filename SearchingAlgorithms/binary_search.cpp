#include <bits/stdc++.h>
using namespace std;

void bsearch(int a[], int n, int key)
{
    sort(a, a + n);  // remove if input is already sorted
    int start = 0, last = n - 1, mid;
    bool found = false;

    while (start <= last)
    {
        mid = (start + last) / 2;
        if (a[mid] == key)
        {
            found = true;
            break;
        }
        else if (a[mid] > key)
            last = mid - 1;
        else
            start = mid + 1;
    }

    if (found)
        cout << key << " found at index " << mid << endl;
    else
        cout << key << " not found\n";
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the array:- ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter the element to be searched:- ";
    cin >> k;

    bsearch(arr, n, k);
    return 0;
}
