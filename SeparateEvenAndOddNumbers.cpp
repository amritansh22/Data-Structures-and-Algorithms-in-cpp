#include<iostream>
using namespace std;

void swap(int * x, int * y){
  int t = * x;
  * x = * y;
  * y = t;
}

void segregate(int array[], int n){
  int left = 0, right = n - 1;
  while (left < right){
    while (array[left] % 2 == 0 && left < right)
      left++;
    while (array[right] % 2 == 1 && left < right)
      right--;
    if (left < right){
      swap( & array[left], & array[right]);
      left++;
      right--;
    }
  }
}

int main(){

  int array[100], n, i;
  cout << "Enter number of elements: ";
  cin >> n;
  cout << "\nEnter elements: ";

  for (i = 0; i < n; i++)
    cin >> array[i];

  cout << "Original array: ";
  for (int i = 0; i < n; i++)
    cout << array[i] << " ";

  segregate(array, n);
  cout << "\nArray after divided: ";

  for (int i = 0; i < n; i++)
    cout << array[i] << " ";

  return 0;

}
