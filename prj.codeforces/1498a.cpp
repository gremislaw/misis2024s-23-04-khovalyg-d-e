#include <iostream>

#define ll long long

using namespace std;

ll gcd(ll a, ll b){
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll gcd_sum(ll num) {
    ll temp = num;
    ll s = 0;
    while (temp != 0) {
        s += temp % 10;
        temp /= 10;
    }
    return s;
}

int main() {
    int n;
    ll a, b;
    ll s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (gcd(a, gcd_sum(a)) == 1) {
            a++;
        }
        cout << a << endl;
    }
}