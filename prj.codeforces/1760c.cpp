#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  int a;
  int b;
  while (t--) {
    vector<int> c;
    cin >> a;
    int maxim1 = 0, maxim2 = 0, maxid1 = 0;
    for (int i = 0; i < a; i++) {
      cin >> b;
      if (maxim2 < b) {
        maxim2 = b;
        maxid1 = i;
      }
      c.push_back(b);
    }
    for (int i = 0; i < a; i++) {
      if (maxim1 < c[i] and i != maxid1) {
        maxim1 = c[i];
      }
    }
    for (int i = 0; i < a; i++) {
      if (maxid1 == i) {
        cout << maxim2 - maxim1 << " ";
        continue;
      }
      cout << -maxim2 + c[i] << " ";
    }
    cout << "\n";
  }
}
