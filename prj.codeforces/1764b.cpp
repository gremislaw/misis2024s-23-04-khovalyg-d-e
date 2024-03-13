#include <iostream>
#include <vector>
#define ll long long
#define ld long double
#define elif else if
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

void solve() {
  int t;
  cin >> t;
  int n, a;
  while (t--) {
    vector<int> semen;
    cin >> n;
    int seken;
    for (int i = 0; i < n; i++) {
      cin >> a;
      semen.push_back(a);
      if (i > 0) {
        seken = gcd(seken, a);
      } else
        seken = a;
    }
    cout << semen[n - 1] / seken << endl;
  }
}

int main() {
  solve();
  return 0;
}
