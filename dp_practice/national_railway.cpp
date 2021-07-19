#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc210/tasks/abc210_d

int main() {
  int h, w; ll c; cin >> h >> w >> c;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep (i, h) rep (j, w) cin >> a[i][j];

  ll ans = INFL;
  rep (_, 2) {
    vector<vector<ll>> dp(h, vector<ll>(w, INFL));
    rep (i, h) rep (j, w) {
      if (i) dp[i][j] = min(dp[i][j], dp[i-1][j]);
      if (j) dp[i][j] = min(dp[i][j], dp[i][j-1]);

      // この時のdp[i][j]はdp[i-1][j]とdp[i][j-1]の最小値
      ans = min(ans, a[i][j] + (i + j) * c + dp[i][j]);

      // ここで(i, j)を含めてdp[i][j]を更新
      dp[i][j] = min(dp[i][j], a[i][j] - (i + j) * c);
    }
    reverse(a.begin(), a.end());
  }

  cout << ans << endl;
  return 0;
}