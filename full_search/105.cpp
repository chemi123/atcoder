#include <iostream>

using namespace std;

// https://atcoder.jp/contests/abc106/tasks/abc106_b

int main() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0) continue;

    int num = 0;
    for (int j = 1; j <= i; ++j) {
      if (i % j == 0) ++num;
    }

    if (num == 8) ++res;
  }
  cout << res << endl;
  return 0;
}