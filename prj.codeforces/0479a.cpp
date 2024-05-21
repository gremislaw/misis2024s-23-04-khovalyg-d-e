#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b == 1 and a != 1 and c != 1) {
    if ((a + b) * c > (c + b) * a)
      cout << (a + b) * c << endl;
    else
      cout << (b + c) * a << endl;
    return 0;
  }

  if (c == 1) swap(a, c);

  if (a == 1)
    b = a + b;
  else
    b = a * b;

  if (c == 1)
    c = b + c;
  else
    c = b * c;

  cout << c << endl;
  return 0;
}
