#include "bits/stdc++.h"

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, s1, s2, a, r;
  cin >> t;
  while (t--) {
    cin >> n;
    a = n;
    s1 = 0;
    r = 0;
    while (a > 0) {
      if (a % 10 == 0) {
        r++;
      }
      a /= 10;
      s1++;
    }
    s2 = s1 - 1;
    cout << s1 - r << endl;
    while (s1--) {
      if (n % 10 == 0) {
        n /= 10;
        continue;
      }
      cout << n % 10;
      for (int i = s1; s2 > i; i++) {
        cout << 0;
      }
      cout << " ";
      n /= 10;
    }
    cout << endl;
  }
  return 0;
}
