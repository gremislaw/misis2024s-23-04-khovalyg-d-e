#include <iostream>
#include <vector>

using namespace std;

int main() {
  double n;
  int res = 0;
  cin >> n;
  vector<int> a(100);
  while (n >= 1000) {
    res += 10;
    n /= 100;
  }
  while (n >= 100) {
    res += 1;
    res -= 100;
  }
  for (int i = 0; i < 100; i++) {
    a[i] = 1;
  }
  return 0;
}