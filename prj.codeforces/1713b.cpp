#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    int f1 = 1, f2 = 1, f3 = 1, down = 0;
    for (int k = 0; k < n - 1; k++) {
      if (a[k] < a[k + 1]) f1 = 0;
    }
    for (int k = 0; k < n - 1; k++) {
      if (a[k] > a[k + 1]) f2 = 0;
    }
    for (int k = 0; k < n - 1; k++) {
      if (down) {
        if (a[k] < a[k + 1]) f3 = 0;
      } else if (a[k] > a[k + 1])
        down = 1;
    }
    if (f1 or f2 or f3)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
