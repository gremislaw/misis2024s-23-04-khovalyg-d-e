#include "bits/stdc++.h"

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int max_pleasure = -1e9, pleasure, f, t;
  for (int i = 0; i < n; i++) {
    cin >> f >> t;

    if (k >= t) {
      pleasure = f;
    } else {
      pleasure = f - (t - k);
    }

    if (pleasure > max_pleasure) {
      max_pleasure = pleasure;
    }
  }
  cout << max_pleasure << endl;
  return 0;
}
