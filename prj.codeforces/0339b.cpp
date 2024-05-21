#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  long long n;
  int m;
  std::cin >> n >> m;
  long long a;
  long long cur = 1;
  long long res = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> a;
    if (cur <= a)
      res += a - cur;
    else
      res += (n - cur) + a;
    cur = a;
  }
  std::cout << res;
}