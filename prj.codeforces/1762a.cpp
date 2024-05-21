#include <cmath>
#include <iostream>
#define ll long long
#define ld long double
#define elif else if
using namespace std;

void solve() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int minCnt1 = 1e6 + 1, minCnt2 = 1e6 + 1, a, suma = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      suma += a;
      if (a % 2 == 0) {
        int cnt1 = 0;
        while (a % 2 == 0) {
          a = floor(a / 2);
          cnt1++;
        }
        if (cnt1 < minCnt1) minCnt1 = cnt1;
      }
      elif (a % 2 != 0) {
        int cnt2 = 0;
        while (a % 2 != 0) {
          a = floor(a / 2);
          cnt2++;
        }
        if (cnt2 < minCnt2) minCnt2 = cnt2;
      }
    }
    if (suma % 2 == 0)
      cout << 0 << "\n";
    else {
      cout << min(minCnt1, minCnt2) << "\n";
    }
  }
}

int main() {
  solve();
  return 0;
}
