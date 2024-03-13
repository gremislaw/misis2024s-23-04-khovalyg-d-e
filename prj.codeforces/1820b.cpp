#include <algorithm>
#include <iostream>
#include <string>
#define ll long long
#define ld long double
#define elif else if
using namespace std;

void solve() {
  int t;
  string s;
  cin >> t;
  while (t--) {
    int maxlen = 0;
    int lena = 0;
    cin >> s;
    s = s + s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        lena++;
        maxlen = max(maxlen, lena);
      } else
        lena = 0;
    }
    int n = s.size() / 2;
    if (maxlen > n)
      cout << (ll)n * n << endl;
    else
      cout << ((ll)(maxlen + 1) / 2) * ((ll)(maxlen + 2) / 2) << endl;
  }
}

int main() {
  solve();
  return 0;
}
