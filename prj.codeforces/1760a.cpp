#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    int k = a + b + c;
    vector<int> o = {a, b, c};
    k -= *max_element(o.begin(), o.end());
    k -= *min_element(o.begin(), o.end());
    cout << k << "\n";
  }
}
