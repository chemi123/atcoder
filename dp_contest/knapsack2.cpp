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

// https://atcoder.jp/contests/dp/tasks/dp_e

int main() {
  ll n, W; cin >> n >> W;
  vector<ll> w(n), v(n);
  ll sum = 0;
  rep (i, n) {
    cin >> w[i] >> v[i];
    sum += v[i];
  }
  vector dp(n, vector<ll>(sum + 1, INFL));
  dp[0][0] = 0, dp[0][v[0]] = w[0];
  reps (i, 1, n) {
    rep (j, sum + 1) {
      if (j < v[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
    }
  }
  ll ans = 0;
  rep (i, n) rep(j, sum + 1) if (dp[i][j] <= W) ans = max(ans, (ll)j);
  cout << ans << endl;
  return 0;
}