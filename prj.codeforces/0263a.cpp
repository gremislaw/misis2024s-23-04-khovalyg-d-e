#include "bits/stdc++.h"

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a;
      if (a == 1) {
        cout << abs(i - 2) + abs(j - 2);
      }
    }
  }
  return 0;
}
