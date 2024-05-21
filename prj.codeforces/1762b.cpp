#include <cmath>
#include <iostream>
#include <vector>
#define ll long long
#define ld long double
#define elif else if
using namespace std;

void solve() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<ll> a;
    ll b;
    for (int i = 0; i < n; i++) {
      cin >> b;
      a.push_back(b);
    }
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < 40; j++) {
        if (a[i] <= (ll)pow(2, j)) {
          cout << i + 1 << " " << (ll)pow(2, j) - a[i] << "\n";
          break;
        }
      }
    }
  }
}

int main() {
  solve();
  return 0;
}
