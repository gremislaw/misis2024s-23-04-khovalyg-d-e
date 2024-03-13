#include <iostream>

using namespace std;

int main() {
    int n;
    int a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int res = 0;
        if (a <= 1399) res = 4;
        if (1400 <= a && a <= 1599) res = 3;
        if (1600 <= a && a <= 1899) res = 2;
        if (1900 <= a) res = 1;
        cout << "Division " << res << endl;
    }
    return 0;
}