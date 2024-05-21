#include "bits/stdc++.h"

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b;
  cin >> a >> b;
  ll res = 1;
  if (a > b) {
    swap(a, b);
  }
  for (int i = 2; i <= a; i++) {
    res *= i;
  }
  cout << res << endl;
  return 0;
}
