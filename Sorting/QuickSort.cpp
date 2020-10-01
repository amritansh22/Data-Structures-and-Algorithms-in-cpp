#include <iostream>
using namespace std;
int partitionPivot(int a[], int start, int end)
{
    int i = start - 1;
    int j = start;
    int pivot = a[end];
    for (j = start; j <= end - 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[end]);
    return i + 1;
}

void quickSort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = partitionPivot(a, start, end);
    quickSort(a, start, p - 1);
    quickSort(a, p + 1, end);
    return;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    cout << "The sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}