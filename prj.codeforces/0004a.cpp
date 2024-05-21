#include <iostream>

#define ll long long
#define ld long double

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int w;
  cin >> w;
  if (w % 2 == 0 and w != 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
