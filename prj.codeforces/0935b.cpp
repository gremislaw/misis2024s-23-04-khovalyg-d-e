#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  int x = 0;
  int y = 0;
  std::string s;
  std::cin >> n;
  std::cin >> s;
  int now = 0;
  int res = 0;
  int last = 0;
  for (auto &el : s) {
    if (el == 'R') {
      x++;
    } else {
      y++;
    }
    if (x == y) {
      now = 0;
    } else if (x > y) {
      now = 1;
    } else {
      now = -1;
    }
    if (last + now == 0 && last != 0) {
      res += 1;
    }
    if (now != 0) {
      last = now;
    }
  }
  std::cout << res;
  return 0;
}
