/**
    given an array and an integer k, find the maximum for each
    and every contiguous subarray of size k.
    Input:
    arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
    k = 3
    Output :
    3 3 4 5 5 5 6
*/

#include <iostream>
#include <queue>

using namespace std;

void find_max(queue<int> q)
{
    int max = 0;
    while (!q.empty())
    {
        if (q.front() > max)
            max = q.front();
        q.pop();
    }

    cout << max << " " ;
    return;
}

void window_max(int arr[], int size, int window_s)
{
    queue<int> q;

    cout << "\nMaximun in each window : " ;

    for (int i=0; i<size; i++)
    {
        if (i < window_s)       // for first window
        {
            q.push(arr[i]);
        }
        else            // for middle window
        {
            find_max(q);
            q.pop();
            q.push(arr[i]);
        }
    }

    // for last window
    find_max(q);

    return;
}

int main()
{
    int size;

    cout << "\nenter number of elements in array : ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "\nenter value " << i + 1 << " of array : ";
        cin >> arr[i];
    }

    int window_s;
    cout << "\nenter window size : ";
    cin >> window_s;

    window_max(arr, size, window_s);

    return 0;
}