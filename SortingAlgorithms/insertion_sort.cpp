#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int i, j, k;
    for(i = 1; i < n; i++){
        k = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > k){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = k;
    }
}

int main(){
    int n;

    cout << "Enter number of element in array: "; 
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: \n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Sorted array: \n";
    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
}