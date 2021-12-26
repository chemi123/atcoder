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

const ll MOD = 10000;

int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<int, int> ump;
  rep (i, n) {
    int d;
    cin >> d;
    cin >> ump[d];
  }
  vector<vector<int>> dp(n+1, vector<int>(6, 0));
  auto it = ump.find(1);
  if (it != ump.end()) dp[1][it->second-1] = 1;
  else dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;
  for (int i = 1; i < n; ++i) {
    it = ump.find(i+1);
    if (it != ump.end()) {
      if (it->second == 1) {
        dp[i+1][0] += (dp[i][1] + dp[i][2] + dp[i][4] + dp[i][5]);
        dp[i+1][3] += dp[i][0];
        dp[i+1][0] %= MOD;
        dp[i+1][3] %= MOD;
      } else if (it->second == 2) {
        dp[i+1][1] += (dp[i][0] + dp[i][2] + dp[i][3] + dp[i][5]);
        dp[i+1][4] += dp[i][1];
        dp[i+1][1] %= MOD;
        dp[i+1][4] %= MOD;
      } else {
        dp[i+1][2] += (dp[i][0] + dp[i][1] + dp[i][3] + dp[i][4]);
        dp[i+1][5] += dp[i][2];
        dp[i+1][2] %= MOD;
        dp[i+1][5] %= MOD;
      }
      continue;
    }
    dp[i+1][0] += (dp[i][1] + dp[i][2] + dp[i][4] + dp[i][5]);
    dp[i+1][1] += (dp[i][0] + dp[i][2] + dp[i][3] + dp[i][5]);
    dp[i+1][2] += (dp[i][0] + dp[i][1] + dp[i][3] + dp[i][4]);
    dp[i+1][3] += dp[i][0];
    dp[i+1][4] += dp[i][1];
    dp[i+1][5] += dp[i][2];
    rep (j, 6) dp[i+1][j] %= MOD;
  }
  int ans = 0;
  rep (i, 6) {
    ans += dp[n][i];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
