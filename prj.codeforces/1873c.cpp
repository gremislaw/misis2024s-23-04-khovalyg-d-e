#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  std::string s;
  int res;
  while (t--) {
    std::vector<std::string> targ;
    for (int i = 0; i < 10; i++) {
      std::cin >> s;
      targ.push_back(s);
    }
    res = 0;
    std::vector<int> p = {5, 4, 3, 2, 1};
    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        t1 = 0;
        t2 = 0;
        if (i > 4) {
          t1 = 1;
        }
        if (j > 4) {
          t2 = 1;
        }
        if (targ[i][j] == 'X') {
          res += p[std::max(abs(i - 4 - t1), abs(j - 4 - t2))];
        }
      }
    }
    std::cout << res << std::endl;
  }
}