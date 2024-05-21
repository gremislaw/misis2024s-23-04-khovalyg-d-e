#include <iostream>
#include <vector>

int main() {
  int t;
  int n;
  long long a;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    long long min_max;
    std::cin >> min_max;
    for (int i = 0; i < n - 1; i++) {
      std::cin >> a;
      min_max &= a;
    }
    std::cout << min_max << std::endl;
  }
  return 0;
}