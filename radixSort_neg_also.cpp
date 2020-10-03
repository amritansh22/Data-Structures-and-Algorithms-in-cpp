// Implementation of radix sort

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void counting_sort(vector<int> &arr, int size, int exp)
{
    int count[10] = {0};
    int output[size];

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++; // for digits in elements of array(from right side)
    }

    // calculating cumulative sum
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // sorting a/c to each digits of elements in array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // storing back in original array the sorted array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(vector<int> &arr, int size)
{
    int max = *max_element(arr.begin(), arr.end()); // maximum element of the array

    for (int exp = 1; (max / exp) > 0; exp *= 10) // looping for number of digits in the max
    {
        counting_sort(arr, size, exp);
    }
}

int main()
{
    int size;
    cout << "\nenter size of array(or count of total numbers) : ";
    cin >> size;

    vector<int> arr(size);
    cout << "\nStart filling your array : \n";
    for (int i = 0; i < size; i++)
    {
        int temp;
        cout << i + 1 << "). ";
        cin >> temp;
        arr[i] = temp;
    }

    int size1 = 0;
    vector<int> neg_arr;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            neg_arr.push_back(abs(arr[i]));
            size1++;
            arr[i] = 0;
        }
    }

    radix_sort(arr, size); // sorting positive array

    if (size1 != 0)
    {
        radix_sort(neg_arr, size1); // sorting negative array

        reverse(neg_arr.begin(), neg_arr.end()); // reverse sorted negative array

        for (int i = 0; i < size1; i++) // merging negative array with positive array
        {
            arr[i] = -neg_arr[i];
        }
    }

    cout << "\nAfter sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}