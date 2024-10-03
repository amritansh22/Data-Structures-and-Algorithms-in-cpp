#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int a[], int size)
{
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        curr_sum += a[i];
        max_sum = max(max_sum, curr_sum);
        curr_sum = max(curr_sum, 0);
    }
    return max_sum;
}
int main()
{
    int i, n;
    cout << "Enter the number of elements \n";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max_sum = maxSubArray(arr, n);
    cout << "Maximum subarray sum is " << max_sum;
    return 0;
}
