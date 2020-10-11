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
  vector<int> d(n+1), c(m+1);
  rep (i, n) cin >> d[i+1];
  rep (i, m) cin >> c[i+1];
  vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
  rep (i, m+1) dp[0][i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j+1] = min(dp[i-1][j] + d[i]*c[j+1], dp[i][j]);
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
