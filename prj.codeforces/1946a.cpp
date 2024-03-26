#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll p = n / 2;
    if (n % 2 == 0) p--;
    ll count = 0;
    vector<ll> l;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      l.push_back(x);
    }
    sort(l.begin(), l.end());
    for (ll i = p; i < n; i++) {
      if (l[i] == l[p])
        count++;
      else
        break;
    }
    cout << count << endl;
  }
}
