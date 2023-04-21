#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool miller_rabin(long long n, int k=5) {
  // Check some basic primality conditions
  if (n < 2) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }

  // Write n-1 as d * 2^r, where d is odd
  long long d = n - 1;
  int r = 0;
  while (d % 2 == 0) {
    d /= 2;
    r++;
  }

  // Perform the Miller-Rabin test k times
  for (int i = 0; i < k; i++) {
    // Choose a random witness a in the range [2, n-2]
    long long a = rand() % (n - 3) + 2;
    long long x = pow(a, d) % n;

    // Check whether a is a witness for the compositeness of n
    if (x == 1 || x == n - 1) {
      continue;
    }
    for (int j = 0; j < r - 1; j++) {
      x = (x * x) % n;
      if (x == n - 1) {
        break;
      }
    }
    if (x != n - 1) {
      return false;
    }
  }
  return true;
}
