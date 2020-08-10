#include <iostream>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

int main() {
  while (1) {
    int n, x;
    cin >> n >> x;
    if (n == 0 && x == 0) break;
    int res = 0;
    for (int i = 1; i <= n - 2; ++i) {
      int l = i + 1;
      int r = n;
      while (l < r) {
        int sum = i + l + r;
        if (sum <= x) {
          if (sum == x) {
            ++res;
          }
          ++l;
        } else {
          --r;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}