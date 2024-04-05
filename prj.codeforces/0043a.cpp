#include <iostream>
#include <string>
using namespace std;
#define long long ll;

void solve() {
  int n, rez(0);
  cin >> n;

  string t, pt;
  while (n--) {
    if (rez != 0) {
      cin >> t;
      if (t == pt) {
        rez++;
      } else {
        rez--;
      }
    } else {
      cin >> pt;
      rez = 1;
    }
  }
  cout << pt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}