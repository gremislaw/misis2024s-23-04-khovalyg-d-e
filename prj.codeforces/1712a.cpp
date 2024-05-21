#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  int n, k;
  int a;
  vector<int> s;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int res = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a > k and i < k) {
        res += 1;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
