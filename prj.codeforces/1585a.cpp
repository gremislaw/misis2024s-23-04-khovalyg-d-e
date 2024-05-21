#include <iostream>
#include <vector>

int main() {
  int t;
  int n;
  std::cin >> t;
  int last;
  int a;
  int res;
  while (t--) {
    last = -1;
    res = 1;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
      std::cin >> a;
      if (res == -1) {
        continue;
      }
      if (a == 1) {
        if (last == 0 || last == -1) {
          res += 1;
        } else {
          res += 5;
        }
      }
      if (last == 0 && a == 0) {
        res = -1;
      }
      last = a;
    }
    std::cout << res << std::endl;
  }
  return 0;
}