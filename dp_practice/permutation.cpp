#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc199/tasks/abc199_e
// 参考: https://atcoder.jp/contests/abc199/submissions/22050932

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<pi>> constraints(n+1);
  rep (i, m) {
    int x, y, z; cin >> x >> y >> z;
    constraints[x].emplace_back(pi(y, z));
  }

  vector<int> popCount(1 << n);
  rep (i, 1 << n) popCount[i] = bitset<18>(i).count();
  vector<ll> dp(1 << n, 0);
  dp[0] = 1;
  rep (S, 1 << n) {
    bool ok = true;
    for (auto [y, z] : constraints[popCount[S]]) {
      int mask = (1 << y) - 1;
      if (popCount[S & mask] > z) {
        ok = false;
        break;
      }
    }
    if (!ok) dp[S] = 0;
    rep (i, n) {
      if (S >> i & 1) continue;
      dp[S | 1 << i] += dp[S];
    }
  }
  cout << dp.back() << endl;

  return 0;
}
