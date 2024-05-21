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
  while (t--) {
    int n;
    std::string s;
    int k;
    std::vector<char> c;
    std::cin >> n >> s >> k;
    c.resize(k);
    for (int i = 0; i < k; i++) {
      std::cin >> c[i];
    }
    std::vector<int> diff;
    diff.push_back(0);
    for (int i = 0; i < n; i++) {
      for (const auto &el : c) {
        if (s[i] == el) {
          diff.push_back(i);
        }
      }
    }
    int res = 0;
    for (int i = 0; i < diff.size() - 1; i++) {
      res = std::max(res, std::abs(diff[i] - diff[i + 1]));
    }
    std::cout << res << '\n';
  }
}
