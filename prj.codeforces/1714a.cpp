#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, h, m;
struct Node {
  int h, m;
} a[N];

bool cmp(struct Node x, struct Node y) {
  if (x.h == y.h) return x.m < y.m;
  return x.h < y.h;
}
void solve() {
  cin >> n >> h >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if ((x < h) || (x == h && y < m)) x += 24;
    a[i] = {x, y};
  }
  sort(a, a + n, cmp);
  if (a[0].m < m) {
    cout << a[0].h - h - 1 << " " << a[0].m + 60 - m << "\n";
  } else {
    cout << a[0].h - h << " " << a[0].m - m << "\n";
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
