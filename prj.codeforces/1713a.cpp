#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  int n;
  int x, y;
  for (int _ = 0; _ < t; _++) {
    cin >> n;
    int right_max = 0;
    int left_max = 0;
    int top_max = 0;
    int bottom_max = 0;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      if (x == 0) {
        if (y < 0)
          if (y < bottom_max) bottom_max = y;
        if (y > 0)
          if (y > top_max) top_max = y;
      } else {
        if (x > 0)
          if (x > right_max) right_max = x;
        if (x < 0)
          if (x < left_max) left_max = x;
      }
    }
    int res = 2 * (-left_max + right_max + top_max + -bottom_max);
    cout << res << "\n";
  }
}
