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

// https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d

int main() {
  int n;
  cin >> n;
  vector<string> flags(5, "");
  rep (i, 5) cin >> flags[i];
  vector<string> vFlags(n, "");
  rep (i, n) rep (j, 5) vFlags[i] += flags[j][i];
  vector<vector<int>> dp(n, vector<int>(3, 0));
  int r = 0, b = 0, w = 0;
  rep (i, 5) {
    if (vFlags[0][i] == 'R') ++r;
    if (vFlags[0][i] == 'B') ++b;
    if (vFlags[0][i] == 'W') ++w;
  }
  dp[0][0] = 5 - r, dp[0][1] = 5 - b, dp[0][2] = 5 - w;
  rep (i, n-1) {
    r = 0, b = 0, w = 0;
    rep (j, 5) {
      if (vFlags[i+1][j] == 'R') ++r;
      if (vFlags[i+1][j] == 'B') ++b;
      if (vFlags[i+1][j] == 'W') ++w;
    }
    dp[i+1][0] = min(dp[i][1] + 5 - r, dp[i][2] + 5 - r);
    dp[i+1][1] = min(dp[i][0] + 5 - b, dp[i][2] + 5 - b);
    dp[i+1][2] = min(dp[i][0] + 5 - w, dp[i][1] + 5 - w);
  }
  cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
  return 0;
}
