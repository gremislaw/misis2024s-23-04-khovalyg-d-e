#include <algorithm>
#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    char c;
    std::string s;
    std::cin >> n >> c >> s;
    int ans = 0;
    s = s + s;
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        for (int j = i; j < 2 * n; j++) {
          if (s[j] == 'g') {
            ans = std::max(ans, j - i);
            i = j;
            break;
          }
        }
      }
    }
    std::cout << ans << "\n";
  }
}