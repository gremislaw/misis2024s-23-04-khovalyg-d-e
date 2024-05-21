#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, m, sx, sy, d, res, f1, f2;
  cin >> t;
  while (t--) {
    cin >> n >> m >> sx >> sy >> d;
    f1 = 1;
    f2 = 1;
    sx--;
    sy--;
    res = n + m - 2;
    for (int x = 0; x < n; x++) {
      if (abs(x - sx) + sy <= d) {
        f1 = 0;
        break;
      }
    }
    for (int y = 0; y < m; y++) {
      if (abs(n - 1 - sx) + abs(y - sy) <= d) {
        f2 = 0;
        break;
      }
    }
    if (f1 && f2) {
      cout << res << endl;
      continue;
    }
    f1 = 1;
    f2 = 1;
    for (int y = 0; y < m; y++) {
      if (abs(y - sy) + sx <= d) {
        f1 = 0;
        break;
      }
    }
    for (int x = 0; x < n; x++) {
      if (abs(m - 1 - sy) + abs(x - sx) <= d) {
        f2 = 0;
        break;
      }
    }
    if (f1 && f2) {
      cout << res << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
