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
  vector<string> s(5);
  rep (i, 5) cin >> s[i];
  vector<vector<int>> dp(n+1, vector<int>(3));
  for (int i = 1; i <= n; ++i) {
    int red = 0, white = 0, blue = 0;
    rep (j, 5) {
      if (s[j][i-1] == 'R') ++red;
      if (s[j][i-1] == 'W') ++white;
      if (s[j][i-1] == 'B') ++blue;
    }
    for (int j = 0; j < 3; ++j) {
      if (j == 0) dp[i][j] = min(dp[i-1][1] + 5 - red, dp[i-1][2] + 5 - red);
      if (j == 1) dp[i][j] = min(dp[i-1][0] + 5 - white, dp[i-1][2] + 5 - white);
      if (j == 2) dp[i][j] = min(dp[i-1][0] + 5 - blue, dp[i-1][1] + 5 - blue);
    }
  }
  int res = 1e9;
  for (auto e : dp[n]) res = min(res, e);
  cout << res << endl;
  return 0;
}
