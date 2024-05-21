#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, k, r, c;
  cin >> t;
  while (t--) {
    cin >> n >> k >> r >> c;
    int a[n][n + n];
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        a[y][x] = 0;
      }
    }
    int now_y = r - 1, now_x = c - 1;
    for (; now_y > -1; now_x++, now_y--) {
      for (int x = now_x; x < n; x += k) {
        a[now_y][x] = 1;
      }
      for (int x = now_x; x > -1; x -= k) {
        a[now_y][x] = 1;
      }
    }
    now_y = r - 1, now_x = c - 1;
    for (; now_y < n; now_x--, now_y++) {
      for (int x = now_x; x < n; x += k) {
        if (x > -1) a[now_y][x] = 1;
      }
      for (int x = now_x; x > -1; x -= k) {
        if (x > -1) a[now_y][x] = 1;
      }
    }

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        if (a[y][x] == 1) {
          cout << 'X';
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }
  }
  return 0;
}
