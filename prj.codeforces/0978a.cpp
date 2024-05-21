#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, temp;
  vector<int> res, a;
  set<int> check;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    a.push_back(temp);
  }
  for (int i = n - 1; i > -1; i--) {
    if (check.find(a[i]) == check.end()) {
      res.push_back(a[i]);
      check.insert(a[i]);
    }
  }
  cout << res.size() << '\n';
  for (int i = res.size() - 1; i > -1; i--) {
    cout << res[i] << " ";
  }
  return 0;
}
