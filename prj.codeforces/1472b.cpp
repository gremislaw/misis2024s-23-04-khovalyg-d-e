#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, s;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    int b[n + 1][n + 1];
    s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % 2 != 0) {
      cout << "no" << endl;
      continue;
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        b[i][j] = 0;
      }
    }
    b[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        if (b[i][j] == 1) {
          b[i + 1][j] = 1;
          b[i + 1][j + a[i]] = 1;
        }
      }
    }

    if (b[n][s / 2] == 1)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}