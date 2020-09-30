#include <iostream>

int gcd_naive(int a, int b) {
  int rem = a%b;
  if(rem == 0)
    return b;
  else
  {
      gcd_naive(b,rem);
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
