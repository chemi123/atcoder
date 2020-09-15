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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> coins(m, 0);
  rep (i, m) cin >> coins[i];
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
  rep (i, m + 1) dp[i][0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j >= coins[i]) dp[i+1][j] = min({dp[i][j-coins[i]] + 1, dp[i+1][j-coins[i]] + 1, dp[i][j]});
      else dp[i+1][j] = dp[i][j];
    }
  }
  cout << dp[m][n] << endl; 
  return 0;
}
