#include <bits/stdc++.h>
using namespace std;

// Partition function (similar to QuickSort)
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] > pivot) { // for Kth largest (descending)
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// Quickselect recursive function
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pi = partition(arr, left, right);
        if (pi == k - 1) return arr[pi];
        else if (pi > k - 1) return quickSelect(arr, left, pi - 1, k);
        else return quickSelect(arr, pi + 1, right, k);
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    vector<int> temp = arr;
    int result = quickSelect(temp, 0, temp.size() - 1, k);
    cout << k << "th largest element is " << result << endl;
    return 0;
}
