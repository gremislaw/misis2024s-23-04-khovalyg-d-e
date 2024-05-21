#include <iostream>
using namespace std;

int main() {
  double a, b, c;
  int t, cnt;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    if (a > b) {
      swap(a, b);
    }
    cnt = (b - a) / (2 * c);
    if ((b - a) / (2 * c) - cnt > 0) {
      cnt++;
    }
    cout << cnt << '\n';
  }
  return 0;
}
