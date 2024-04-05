#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll& i : v) cin >> i;
  if (v[0] % 2 != v[1] % 2 and v[0] % 2 != v[2] % 2) {
    cout << 1 << endl;
    return;
  }
  if (v[n - 1] % 2 != v[n - 2] % 2 and v[n - 1] % 2 != v[n - 3] % 2) {
    cout << n << endl;
    return;
  }
  for (ll i = 1; i < n - 1; i++) {
    if (v[i] % 2 != v[i - 1] % 2 and v[i] % 2 != v[i + 1] % 2) {
      cout << i + 1 << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}