#include <iostream>
#include <set>
#include <string>
#define ll long long
#define ld long double
#define elif else if
using namespace std;

void solve() {
  int t;
  int n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    set<char> even;
    set<char> odd;
    int res = 1;
    for (int i = 0; i < n; i += 2) even.insert(s[i]);
    for (int j = 1; j < n; j += 2) odd.insert(s[j]);
    for (int i : even)
      if (odd.find(i) != odd.end()) {
        res = 0;
      }
    for (int i : odd)
      if (even.find(i) != even.end()) {
        res = 0;
      }
    if (!res)
      cout << "nO" << endl;
    else
      cout << "yeS" << endl;
  }
}

int main() {
  solve();
  return 0;
}
