#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a;
    int b;
    std::string s;
    std::cin >> a >> b >> s;
    int n = s.length();
    bool error = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[n - i - 1] && s[i] != '?') {
        if (s[i] == '0')
          a--;
        else
          b--;
      }
      if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1])
        error = true;
    }
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != '?' && s[n - i - 1] == '?') {
        s[n - i - 1] = s[i];
        if (s[i] == '0')
          a -= 2;
        else
          b -= 2;
      } else if (s[i] == '?' && s[n - i - 1] != '?') {
        s[i] = s[n - i - 1];
        if (s[i] == '0')
          a -= 2;
        else
          b -= 2;
      }
    }
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == '?' && s[n - i - 1] == '?') {
        if (a >= 2) {
          s[i] = s[n - i - 1] = '0';
          a -= 2;
        } else if (b >= 2) {
          s[i] = s[n - i - 1] = '1';
          b -= 2;
        } else {
          error = true;
        }
      }
    }
    if (s[n / 2] == '?') {
      if (a > 0) {
        s[n / 2] = '0';
        a--;
      } else {
        s[n / 2] = '1';
        b--;
      }
    }
    if (error || a != 0 || b != 0) {
      std::cout << -1 << std::endl;
    } else {
      for (int i = 0; i < n; i++) {
        std::cout << s[i];
      }
      std::cout << std::endl;
    }
  }
}
// 011101101110