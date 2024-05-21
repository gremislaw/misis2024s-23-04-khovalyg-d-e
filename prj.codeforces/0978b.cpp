#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int res = 0, now_x = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'x') {
      now_x++;
      if (now_x > 2) {
        res++;
      }
    } else {
      now_x = 0;
    }
  }
  cout << res << endl;
  return 0;
}
