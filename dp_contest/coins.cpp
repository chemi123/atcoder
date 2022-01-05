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
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/dp/tasks/dp_i

int main() {
  int n; cin >> n;
  vector<ld> p(n);
  rep (i, n) cin >> p[i];
  vector<vector<ld>> dp(n, vector<ld>(n + 1));
  dp[0][0] = (ld)1 - p[0], dp[0][1] = p[0];
  reps (i, 1, n) {
    rep (j, n + 1) {
      if (j > i + 1) break;
      dp[i][j] = dp[i-1][j] * ((ld)1 - p[i]);
      if (j > 0) dp[i][j] += dp[i-1][j-1] * p[i];
    }
  }
  ld ans = 0;
  rep (i, n + 1) if (2 * i > n) ans += dp.back()[i];
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}