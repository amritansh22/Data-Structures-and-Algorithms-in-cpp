//Sub array of size k with palindromic concatination slideing window challange 4 time complexity O(n^2)
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPalindrome(int n)
{
    int temp = n;
    int number = 0;
    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }
    if (number == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findPalindromicSubArray(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }
    if (isPalindrome(num))
    {
        return 0;
    }
    for (int j = k; j < arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];
        if (isPalindrome(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int ans = findPalindromicSubArray(arr, k);
    if (ans == -1)
    {
        cout << "Palindromic sub array dos't exist" << endl;
    }
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}