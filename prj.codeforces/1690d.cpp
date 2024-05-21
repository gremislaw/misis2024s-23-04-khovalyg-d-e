#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    int k;
    std::string s;
    std::cin >> n >> k >> s;
    int b = 0;
    int w = 0;
    int i = 0;
    for (; i < k; i++) {
      if (s[i] == 'W')
        w++;
      else
        b++;
    }
    int bmax = b;
    for (i = k; i < n; i++) {
      if (s[i] == 'W') {
        w++;
      } else {
        b++;
      }
      if (s[i - k] == 'W') {
        w--;
      } else {
        b--;
      }
      if (b > bmax) bmax = b;
    }
    std::cout << k - bmax << "\n";
  }
}