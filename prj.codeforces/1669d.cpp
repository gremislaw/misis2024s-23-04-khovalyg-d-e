#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    int k;
    std::string s;
    std::cin >> n >> s;
    int b = 0;
    int r = 0;
    int flag = 0;
    s = s + "W";
    for (int i = 0; i < n + 1; i++) {
      if (s[i] == 'R') r = 1;
      if (s[i] == 'B') b = 1;
      if (s[i] == 'W') {
        if (r ^ b) flag = 1;
        r = 0;
        b = 0;
      }
    }
    if (flag)
      std::cout << "NO"
                << "\n";
    else
      std::cout << "YES"
                << "\n";
  }
}