#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    string s1, s2;
    cin >> s1 >> s2;
    bool flag1 = find(s1.begin(), s1.end(), 'S') != s1.end();
    bool flag2 = find(s2.begin(), s2.end(), 'S') != s2.end();
    if (s1 == s2) {
      cout << "=\n";
    } else if ((flag1 and !flag2) or
               (!flag1 and !flag2 and s2.length() > s1.length()) or
               (flag1 and flag2 and s1.length() > s2.length()) or
               (!flag2 and s1 == "M") or (flag1 and s2 == "M")) {
      cout << "<\n";
    } else if ((!flag1 and flag2) or
               (!flag1 and !flag2 and s2.length() < s1.length()) or
               (flag1 and flag2 and s1.length() < s2.length()) or
               (!flag1 and s2 == "M") or (flag2 and s1 == "M")) {
      cout << ">\n";
    }
  }
}