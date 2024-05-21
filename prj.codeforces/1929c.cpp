#include <iostream>
#define ll long long
using namespace std;

void solve() {
  ll k = 1, x = 1, a = 1;
  cin >> k >> x >> a;

  ll ySum = 0;
  for (int i = 1; i <= x + 1; i++) {
    ll yCur = ySum / (k - 1) + 1;
    ySum += yCur;
    if (ySum > a) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    solve();
  }
}