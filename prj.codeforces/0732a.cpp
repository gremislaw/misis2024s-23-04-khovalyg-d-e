#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int k, r;
  cin >> k >> r;
  int now = k;
  for (int i = 1; i < 10; i++) {
    if (now % 10 == r or now % 10 == 0) {
      cout << i << endl;
      break;
    }
    now += k;
  }
  return 0;
}
