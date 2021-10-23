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
using pd = pair<double, double>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;
const double PI = 3.141592653589793;

// https://atcoder.jp/contests/typical90/tasks/typical90_i

int main() {
  int n; cin >> n;
  vector<pd> points(n);
  rep (i, n) {
    double x, y; cin >> x >> y;
    points[i] = pd(x, y);
  }

  double ans = 0;
  rep (i, n) {
    auto [baseX, baseY] = points[i];
    vector<double> angles;
    angles.reserve(n);
    rep (j, n) {
      if (j == i) continue;
      auto [nextX, nextY] = points[j];
      double angle = atan2((nextY - baseY), (nextX - baseX)) * 180 / PI;
      if (angle >= 0) angles.emplace_back(angle);
      else angles.emplace_back(360 + angle);
    }
    sort(angles.begin(), angles.end());
    for (auto base : angles) {
      double searchAngle = base + 180;
      if (searchAngle > 360) searchAngle -= 360;
      auto it = lower_bound(angles.begin(), angles.end(), searchAngle);
      if (it == angles.begin()) {
        double angle = abs(*it - base);
        if (angle > 180) angle = 360 - angle;
        ans = max(ans, angle);
      } else if (it == angles.end()){
        double angle = abs(angles.back() - base);
        if (angle > 180) angle = 360 - angle;
        ans = max(ans, angle);
      } else {
        double angle1 = abs(*it - base);
        if (angle1 > 180) angle1 = 360 - angle1;
        double angle2 = abs(*(it-1) - base);
        if (angle2 > 180) angle2 = 360 - angle2;
        ans = max(ans, max(angle1, angle2));
      }
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}