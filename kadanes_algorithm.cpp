#include <bits/stdc++.h>
using namespace std;
int kadanes_algorithm(int a[], int n) {
  int ans = a[0], ans_l = 0, ans_r = 0;
  int sum = 0, minus_pos = -1;

  for (int r = 0; r < n; ++r) {
    sum += a[r];
    if (sum > ans) {
      ans = sum;
      ans_l = minus_pos + 1;
      ans_r = r;
    }
    if (sum < 0) {
      sum = 0;
      minus_pos = r;
    }
  }
  return sum;
}
int main() {
  int n;
  cout << "Enter the number of elements \n";
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << kadanes_algorithm(a, n);
}
