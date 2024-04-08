#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define mod 1000000007

bool checkPrime(int n) {
  vector<int> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return isPrime[n];
}

void getPrimes(int n, vector<int>& primeFactors) {
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      primeFactors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) primeFactors.push_back(n);
}

void primesFromTwoToN(int n, vector<int> primeFactors[]) {
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primeFactors[i].push_back(i);
      for (int j = 2 * i; j <= n; j += i) {
        isPrime[j] = false;
        primeFactors[j].push_back(i);
      }
    }
  }
}

char get(int i) { return 'a' + i - 1; }

int modExpo(int a, int b) {
  if (b == 0) return 1;
  int c = modExpo(a, b / 2);
  if (b % 2) {
    return ((a * c) % mod * c) % mod;
  }
  return (c * c) % mod;
}

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> a(200002);

  while (n--) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }

  for (int i = 1; i < 200002; i++) {
    a[i] += a[i - 1];
  }

  for (int i = 1; i < 200002; i++) {
    if (a[i] >= k)
      a[i] = 1;
    else
      a[i] = 0;
  }

  for (int i = 1; i < 200002; i++) {
    a[i] += a[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[l - 1] << endl;
  }
}

signed main() {
  int test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
