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

// https://atcoder.jp/contests/abc219/tasks/abc219_d

int main() {
  int n, x, y; cin >> n >> x >> y;
  vector<int> a(n), b(n);
  rep (i, n) cin >> a[i] >> b[i];
  vector dp(n + 1, vector<vector<int>>(x + 1, vector<int>(y + 1, INF)));
  dp[0][0][0] = 0;
  rep (i, n) rep(j, x + 1) rep(k, y + 1) {
      int nextJ = min(x, j + a[i]);
      int nextK = min(y, k + b[i]);
      dp[i+1][nextJ][nextK] = min(dp[i+1][nextJ][nextK], dp[i][j][k] + 1);
      dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
  }
  int ans = dp[n][x][y];
  cout << ((ans == INF) ? -1 : ans) << endl;
  return 0;
}