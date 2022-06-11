#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// 原点に平行移動してローテートしてからまた平行移動する素朴な解法
// https://atcoder.jp/contests/abc197/tasks/abc197_d

pair<long double, long double> rotate(long double x, long double y, long double radian) {
  long double retX = cos(radian) * x - sin(radian) * y;
  long double retY = sin(radian) * x + cos(radian) * y;
  return {retX, retY};
}

int main() {
  long double n; cin >> n;
  long double x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
  long double px = (x0 + x1) / 2;
  long double py = (y0 + y1) / 2;
  long double theta = M_PI * 2 / n;
  long double x2 = x0 - px;
  long double y2 = y0 - py;
  auto [ansX, ansY] = rotate(x2, y2, theta);
  cout << fixed << setprecision(10) << ansX + px << " " << ansY + py << endl;
  return 0;
}