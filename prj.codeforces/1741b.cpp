#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      for (int i = n; i > 0; i--) {
        cout << i << " ";
      }
      cout << "\n";
    } else if (n <= 3) {
      cout << "-1\n";
    } else {
      int i = n;
      int els = n;
      bool flag = 0;
      while (i != 0) {
        if (els == n / 2 + 1) {
          els = -1;
          flag = 1;
        }
        if (!flag) {
          els--;
        } else {
          els++;
        }
        cout << els + 1 << " ";
        i--;
      }
      cout << "\n";
    }
  }
}
