// counting sort implementation

#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(int arr[], int size)
{
    int max = *max_element(arr, arr + size);
    int min = *min_element(arr, arr + size);

    int range = max - min + 1;

    int count[range] = {0};

    // counting frequency of numbers in array
    for (int i = 0; i < size; i++)
    {
        count[arr[i] - min]++;
    }

    // calculating cumulative sum
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    int output[size];

    // making the new sorted array
    for (int i = size - 1; i >= 0; i--) // traversing from backward for stability
    {
        output[count[arr[i]-min] - 1] = arr[i];
        count[arr[i]-min]--;
    }

    // copying the sorted array in original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int size;
    cout << "\nenter size of the array : ";
    cin >> size;

    int arr[size];
    cout << "Start entering values in array (numeric type) : ";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ") ";
        cin >> arr[i];
    }

    counting_sort(arr, size);

    cout << "After sorting : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
