#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

// https://atcoder.jp/contests/arc054/tasks/arc054_b

double f(double x, double p) {
  return x + p / pow(2, x / 1.5);
}

int main() {
  double p;
  cin >> p;
  double l = 0, r = 1e15;
  int cnt = 1000;
  while (cnt--) {
    double x1 = (l * 2 + r) / 3;
    double x2 = (l + r * 2) / 3;
    double f1 = f(x1, p);
    double f2 = f(x2, p);
    if (f1 > f2) {
      l = x1;
    } else {
      r = x2;
    }
  }
  cout << fixed << setprecision(20) << f(r, p) << endl;
  return 0;
}
