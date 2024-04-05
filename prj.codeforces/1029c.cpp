#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  multiset<ll> l, r;
  ll n;
  cin >> n;
  vector<ll> lg(n + 1), rg(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> lg[i] >> rg[i];
    l.insert(lg[i]);
    r.insert(rg[i]);
  }
  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    l.erase(l.find(lg[i]));
    r.erase(r.find(rg[i]));
    ll lf = *l.rbegin(), rf = *r.begin();
    if (lf <= rf) {
      ans = max(ans, rf - lf);
    }
    l.insert(lg[i]);
    r.insert(rg[i]);
  }
  cout << ans << endl;
  return 0;
}
