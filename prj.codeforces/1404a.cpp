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
    std::vector<std::vector<char>> pos(k);
    int a_cnt = 0;
    int b_cnt = 0;
    bool error = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') continue;
      if (pos[i % k].empty())
        pos[i % k].push_back(s[i]);
      else if (pos[i % k][0] != s[i] && pos[i % k].size() < 2)
        pos[i % k].push_back(s[i]);
      if (pos[i % k].size() > 1) {
        error = 1;
      }
    }
    if (error) {
      std::cout << "NO" << std::endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '?' && !pos[i % k].empty()) {
        s[i] = pos[i % k][0];
      }
    }
    for (int i = 0; i < k; i++) {
      if (s[i] == '1') {
        a_cnt++;
      } else if (s[i] == '0') {
        b_cnt++;
      }
    }
    for (int i = 0; i < k; i++) {
      if (s[i] == '?' && pos[i].empty()) {
        if (a_cnt > b_cnt) {
          s[i] = '0';
          b_cnt++;
          pos[i].push_back('0');
        } else {
          s[i] = '1';
          a_cnt++;
          pos[i].push_back('1');
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '?' && !pos[i % k].empty()) {
        s[i] = pos[i % k][0];
      }
    }
    for (int i = 0; i < k; i++) {
      pos[i].clear();
    }
    for (int i = 0; i < n; i++) {
      if (pos[i % k].empty()) pos[i % k].push_back(s[i]);
      if (pos[i % k][0] != s[i] && pos[i % k].size() < 2)
        pos[i % k].push_back(s[i]);
      if (pos[i % k].size() > 1) {
        error = 1;
      }
    }
    a_cnt = 0;
    b_cnt = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == '1') {
        a_cnt++;
      } else {
        b_cnt++;
      }
    }
    if (a_cnt != b_cnt) {
      error = 1;
    }
    if (error) {
      std::cout << "NO" << std::endl;
      continue;
    }
    std::cout << "YES" << std::endl;
  }
}
