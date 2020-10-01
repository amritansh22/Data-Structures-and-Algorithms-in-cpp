#include <iostream>

// simple Kadane's algorithm to
// find maximum subarray sum
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

int main() {
  return 0;
}
