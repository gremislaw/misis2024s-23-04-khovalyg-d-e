#include <iostream>

using namespace std;

int main() {
  int n, a;
  cin >> n;
  long long cnt = 0, cntminus = 0, cntall = 0, ind = 0;
  for (int i = 1; i <= n; i++){
    cin >> a;
    cntall += i;
    if (a < 0){
      cntminus += i - ind;
      ind = i - ind;
    }
    else{
      cntminus += ind;
    }
  }
  cout << cntminus << " " << cntall - cntminus << endl;
  return 0;
}
