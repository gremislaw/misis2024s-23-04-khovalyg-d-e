#include <iostream>
#include <set>
using namespace std;

int main() {
  int n, x, t, tmp, cur;
  cin >> t;
  while (t--) {
    set<int> a;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      a.insert(tmp);
    }
    cur = 0;
    while (x > 0) {
      cur++;
      if (a.find(cur) == a.end()) {
        x--;
      }
    }
    while (a.find(cur + 1) != a.end()) {
      cur++;
    }
    cout << cur << endl;
  }
  return 0;
}
