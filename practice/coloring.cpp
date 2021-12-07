#include <algorithm>
#include <bitset>
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

// https://atcoder.jp/contests/arc051/tasks/arc051_a

// 長方形に円が内包されるかの判定
bool rectangleIncludesCircle(int x1, int y1, int r, int x2, int y2, int x3, int y3) {
  return (y1 + r <= y3 && y1 - r >= y2 && x1 - r >= x2 && x1 + r <= x3);
}

// 円に長方形が内包されるかの判定
bool circleIncludesRectangle(int x1, int y1, int r, int x2, int y2, int x3, int y3) {
  int l1 = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
  int l2 = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y3) * abs(y1 - y3);
  int l3 = abs(x1 - x3) * abs(x1 - x3) + abs(y1 - y2) * abs(y1 - y2);
  int l4 = abs(x1 - x3) * abs(x1 - x3) + abs(y1 - y3) * abs(y1 - y3);
  return (l1 <= r * r && l2 <= r * r && l3 <= r * r && l4 <= r * r);
}

int main() {
  int x1, y1, r; cin >> x1 >> y1 >> r;
  int x2, y2, x3, y3; cin >> x2 >> y2 >> x3 >> y3;
  if (rectangleIncludesCircle(x1, y1, r, x2, y2, x3, y3)) {
    cout << "NO" << endl;
    cout << "YES" << endl;
    return 0;
  }

  if (circleIncludesRectangle(x1, y1, r, x2, y2, x3, y3)) {
    cout << "YES" << endl;
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << "YES" << endl;

  return 0;
}