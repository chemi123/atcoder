#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
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

// https://atcoder.jp/contests/abc167/tasks/abc167_c

int main() {
  int n, m, x; cin >> n >> m >> x;
  vector<int> cost(n);
  vector<vector<int>> effect(n, vector<int>(m));
  rep (i, n) {
    cin >> cost[i];
    rep (j, m) cin >> effect[i][j];
  }

  int ans = INF;
  rep (i, 1 << n) {
    int sum = 0;
    vector<int> skill(m);

    rep (bit, n) if (i >> bit & 1) {
      sum += cost[bit];
      rep (j, m) skill[j] += effect[bit][j];
    }

    bool ok = true;
    for (auto e : skill) {
      if (e < x) {
        ok = false;
        break;
      }
    }
    if (ok) ans = min(ans, sum);
  }

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
