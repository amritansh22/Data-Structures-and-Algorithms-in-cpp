#include <iostream>

/*
    Simple Kadane's algorithm to
    find maximum subarray sum
*/

int kadane(int a[], int n) {
  int highest = 0, ending = 0;
  int i;
  for (i = 0; i < n; i++) {
    ending = ending + a[i];
    if (ending < 0) ending = 0;
    if (highest < ending) highest = ending;
  }
  return highest;
}

/*
    Function returns maximum
    circular contiguous sum in a[]
*/

int maxCircularSum(int a[], int n) {
  int max = kadane(a, n);
  int wrap = 0, i;
  for (i = 0; i < n; i++) {
    wrap += a[i];
    a[i] = -a[i];
  }
  wrap = wrap + kadane(a, n);
  return (wrap > max) ? wrap : max;
}

int main() { return 0; }
