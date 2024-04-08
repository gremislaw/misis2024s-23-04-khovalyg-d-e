#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;

  return true;
}
void inverse(int n[], int a) {
  int v[a];
  for (int i = 0; i < a; i++) v[n[i] - 1] = i + 1;
  for (int i = 0; i < a; i++) n[i] = v[i];
  return;
}
bool isSorted(int a[], int n) {
  bool k = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] < a[i]) {
      k = 0;
      break;
    }
  }
  return k;
}
bool isrSorted(int a[], int n) {
  bool k = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] > a[i]) {
      k = 0;
      break;
    }
  }
  return k;
}
void solve() {
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) cin >> v[i];
  if (v[0] == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
}