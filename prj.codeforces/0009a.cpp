#include <iostream>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, u, d;
  cin >> a >> b;

  int mx = max(a, b);
  if (mx == 1) {
    u = 1;
    d = 1;
  } else if (mx == 2) {
    u = 5;
    d = 6;
  } else if (mx == 3) {
    u = 2;
    d = 3;
  } else if (mx == 4) {
    u = 1;
    d = 2;
  } else if (mx == 5) {
    u = 1;
    d = 3;
  } else {
    u = 1;
    d = 6;
  }
  cout << u << "/" << d;
}
