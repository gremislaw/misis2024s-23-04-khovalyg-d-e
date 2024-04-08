#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      x ^= a[i];
    }
    if (n % 2) {
      cout << x << endl;
    } else {
      if (x == 0) {
        cout << 0 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}