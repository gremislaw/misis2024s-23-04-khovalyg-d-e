#include <iostream>

using namespace std;

int main() {
  int n;
  int a;
  int res = 0;
  cin >> n >> a;
  int mina = a, maxa = a;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    if (a < mina) {
      mina = a;
      res++;
    }
    if (a > maxa) {
      maxa = a;
      res++;
    }
  }
  cout << res << endl;
  return 0;
}