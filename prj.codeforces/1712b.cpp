#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  int n, k;
  int a;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    vector<int> sorted;
    vector<int> reversed;
    cin >> n;
    int k = 0;
    if (n % 2 == 1) {
      k = 2;
      reversed.push_back(1);
    }
    for (int i = 1 + k; i <= n; i += 2) {
      sorted.push_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
      reversed.push_back(i);
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << reversed[cnt1] << " ";
        cnt1++;
      } else {
        cout << sorted[cnt2] << " ";
        cnt2++;
      }
    }

    cout << "\n";
  }
  return 0;
}
