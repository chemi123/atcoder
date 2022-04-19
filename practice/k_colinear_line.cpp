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

// https://atcoder.jp/contests/abc248/tasks/abc248_e

bool colinear(int x1, int x2, int x3, int y1, int y2, int y3) {
  return  (y3 - y1) * (x2 - x1) == (y2 - y1) * (x3 - x1);
}

int main() {
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  vector<pi> xy(n);
  rep (i, n) cin >> xy[i].first >> xy[i].second;
  set<vector<pi>> s;
  rep (i, n) {
    auto [x1, y1] = xy[i];
    rep (j, n) if (j != i) {
      auto [x2, y2] = xy[j];
      vector<pi> v{pi(x1, y1), pi(x2, y2)};
      rep (K, n) if (K != i && K != j) {
        auto [x3, y3] = xy[K];
        if (x1 == x2) {
          if (x3 == x1) v.emplace_back(pi(x3, y3));
        } else if (y1 == y2) {
          if (y3 == y1) v.emplace_back(pi(x3, y3));
        } else {
          if (colinear(x1, x2, x3, y1, y2, y3)) v.emplace_back(pi(x3, y3));
        }
      }
      sort(v.begin(), v.end());
      s.emplace(v);
    }
  }
  int ans = 0;
  for (auto& v : s) if (v.size() >= k) ++ans;
  cout << ans << endl;
  return 0;
}