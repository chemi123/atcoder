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
using dpi = pair<pi, pi>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc218/tasks/abc218_d

int main() {
  int n; cin >> n;
  vector<pi> xy(n);
  rep (i, n) {
    int x, y; cin >> x >> y;
    xy[i] = pi(x, y);
  }
  set<dpi> s;
  rep (i, n) rep (j, n) if (j != i) {
    auto [x1, y1] = xy[i];
    auto [x2, y2] = xy[j];
    if (y1 == y2) s.emplace(dpi(pi(min(x1, x2), y1), pi(max(x1, x2), y2)));
  }
  vector<dpi> v;
  for (auto p : s) v.emplace_back(p);
  int ans = 0;
  rep (i, v.size()) reps (j, i + 1, v.size()) if (j != i) {
    auto [p1, p2] = v[i];
    auto [p3, p4] = v[j];
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    auto [x3, y3] = p3;
    auto [x4, y4] = p4;
    if (y1 == y3) continue;
    if ((x1 == x3 && x2 == x4) || (x1 == x4 && x2 == x3)) ++ans;
  }
  cout << ans << endl;
  return 0;
}