#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n), c(m);
  rep (i, n) cin >> d[i];
  rep (i, m) cin >> c[i];
  vector<vector<int>> dp(m, vector<int>(n+1, 1e9));
  dp[0][1] = d[0] * c[0];
  rep (i, m) dp[i][0] = 0;
  rep (i, m-1) {
    rep (j, n) {
      if (dp[i][j] == 1e9) break;
      dp[i+1][j+1] = min(dp[i][j+1], dp[i][j] + c[i+1] * d[j]);
    }
  }
  cout << dp[m-1][n] << endl;
  return 0;
}
