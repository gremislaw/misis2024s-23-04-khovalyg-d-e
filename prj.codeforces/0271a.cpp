#include "bits/stdc++.h"

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int y;
  cin >> y;
  for (int i = y + 1; i <= 10000; i++) {
    int a, b, c, d;
    a = i / 1000;
    b = i / 100 % 10;
    c = i / 10 % 10;
    d = i % 10;
    if (a != b and b != c and c != d and a != c and a != d and b != d) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
