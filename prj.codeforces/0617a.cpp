#include "bits/stdc++.h"

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x, res;
  cin >> x;
  res = x / 5;
  if (x % 5 == 0)
    cout << res << endl;
  else
    cout << res + 1 << endl;
}
