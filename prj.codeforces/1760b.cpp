#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  int a;
  string b;
  while (t--) {
    cin >> a >> b;
    int maxim = 0;
    for (int i = 0; i < a; i++) {
      if ((int)b[i] > maxim) {
        maxim = (int)b[i];
      }
    }
    cout << maxim - (int)'a' + 1 << "\n";
  }
}
