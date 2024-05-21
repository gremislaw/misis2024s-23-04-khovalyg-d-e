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
    int k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int res = 0;
    for (int i = 0, j = k; i < n; i++, j++) {
      if (s[i] == 'B') {
        res++;
        i += k - 1;
        j += k - 1;
      }
    }
    std::cout << res << std::endl;
  }
}