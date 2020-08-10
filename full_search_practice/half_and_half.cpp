#include <iostream>

using namespace std;

// https://atcoder.jp/contests/abc095/tasks/arc096_a

int main() {
  uint64_t a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  uint64_t res = 10e15;
  res = min(res, a * x + b * y);
  if (x > y) {
    res = min(res, 2 * c * x);
    res = min(res, 2 * c * y + a * (x - y));
  } else {
    res = min(res, 2 * c * y);
    res = min(res, 2 * c * x + b * (y - x));
  }
  cout << res << endl;
  return 0;
}