#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
  double p;
  cin >> p;
  double l = 0, r = 1e15;
  int cnt = 1000;
  auto f = [p](double x) { return x + p / pow(2, x / 1.5); };
  while (cnt--) {
    double x1 = (l * 2 + r) / 3, x2 = (l + r * 2) / 3;
    auto fx1 = f(x1), fx2 = f(x2);
    if (fx1 > fx2) l = x1;
    else r = x2;
  }
  cout << fixed << setprecision(20) << f(r) << endl;
  return 0;
}