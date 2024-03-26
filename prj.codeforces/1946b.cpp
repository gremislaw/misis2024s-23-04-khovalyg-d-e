#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power(ll x, ll y, ll p) {
  ll res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  ll sum = 0, maxi = 0, total = 0;
  for (ll i = 0; i < n; i++) {
    total += v[i];
    sum = sum + v[i];
    maxi = max(maxi, sum);
    sum = max(0LL, sum);
  }

  if (maxi == 0LL) {
    cout << (total % MOD + MOD) % MOD << "\n";
    return;
  }

  ll y = maxi;

  ll big = (y % MOD * power(2, k, MOD) % MOD) % MOD;

  ll a1 = (big % MOD - y % MOD) % MOD;

  ll ans = (a1 % MOD + total % MOD + 2 * MOD) % MOD;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}