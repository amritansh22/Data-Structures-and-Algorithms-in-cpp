#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ---- Forward Declarations ----
int partition(vector<int>& arr, int left, int right);
int quickSelect(vector<int>& arr, int left, int right, int k);
int kthLargest_quickselect(vector<int> arr, int k);

// ---- Sorting method ----
int kthLargest_sort(vector<int> arr, int k) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k - 1];
}

// ---- nth_element method ----
int kthLargest_nth(vector<int> arr, int k) {
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), greater<int>());
    return arr[k - 1];
}

// ---- Quickselect method ----
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] > pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pi = partition(arr, left, right);
        if (pi == k - 1) return arr[pi];
        else if (pi > k - 1) return quickSelect(arr, left, pi - 1, k);
        else return quickSelect(arr, pi + 1, right, k);
    }
    return -1;
}

int kthLargest_quickselect(vector<int> arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, k);
}

// ---- Main ----
int main() {
    vector<int> arr(1e5);
    generate(arr.begin(), arr.end(), rand);
    int k = 50;

    auto start = high_resolution_clock::now();
    kthLargest_sort(arr, k);
    auto end = high_resolution_clock::now();
    cout << "Sorting Method: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    kthLargest_nth(arr, k);
    end = high_resolution_clock::now();
    cout << "nth_element: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    kthLargest_quickselect(arr, k);
    end = high_resolution_clock::now();
    cout << "QuickSelect: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    
    return 0;
}
