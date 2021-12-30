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

// https://atcoder.jp/contests/dp/tasks/dp_d

int main() {
  int n, W; cin >> n >> W;
  vector<ll> w(n), v(n);
  rep (i, n) cin >> w[i] >> v[i];
  vector dp(n, vector<ll>(W + 1));
  reps (i, w[0], W + 1) dp[0][i] = v[0];
  reps (i, 1, n) {
    rep (j, W + 1) {
      if (j < w[i]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}