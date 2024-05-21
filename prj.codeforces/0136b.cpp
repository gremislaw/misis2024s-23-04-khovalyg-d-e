#include <math.h>

#include <iostream>

int main() {
  int a;
  int b = 0;
  int c;
  std::cin >> a >> c;
  for (int i = 1; i < 10; i++) {
    b += (int)(c % (int)pow(10, i) / pow(10, i - 1) -
               a % (int)pow(10, i) / pow(10, i - 1)) *
         3 * pow(10, i - 1);
  }
  std::cout << b << std::endl;
  return 0;
}