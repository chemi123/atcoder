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

// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n+1);
  rep (i, k) {
    int d, t;
    cin >> d >> t;
    s[d] = t;
  }
  vector<vector<int>> dp(n+1, vector<int>(7, 0));
  if (s[1] > 0) dp[1][s[1]] = 1;
  else  dp[1][1] = 1, dp[1][2] = 1, dp[1][3] = 1;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (dp[i][j] == 0) continue;
      switch (j) {
        case 1:
          if (s[i+1] > 0) {
            if (s[i+1] == 1) dp[i+1][4] = (dp[i+1][4] + dp[i][j]) % MOD;
            else dp[i+1][s[i+1]] = (dp[i+1][s[i+1]] + dp[i][j]) % MOD;
          } else {
            dp[i+1][2] = (dp[i+1][2] + dp[i][j]) % MOD;
            dp[i+1][3] = (dp[i+1][3] + dp[i][j]) % MOD;
            dp[i+1][4] = (dp[i+1][4] + dp[i][j]) % MOD;
          }
          break;
        case 2:
          if (s[i+1] > 0) {
            if (s[i+1] == 2) dp[i+1][5] = (dp[i+1][5] + dp[i][j]) % MOD;
            else dp[i+1][s[i+1]] = (dp[i+1][s[i+1]] + dp[i][j]) % MOD;
          } else {
            dp[i+1][1] = (dp[i+1][1] + dp[i][j]) % MOD;
            dp[i+1][3] = (dp[i+1][3] + dp[i][j]) % MOD;
            dp[i+1][5] = (dp[i+1][5] + dp[i][j]) % MOD;
          }
          break;
        case 3:
          if (s[i+1] > 0) {
            if (s[i+1] == 3) dp[i+1][6] = (dp[i+1][6] + dp[i][j]) % MOD;
            else dp[i+1][s[i+1]] = (dp[i+1][s[i+1]] + dp[i][j]) % MOD;
          } else {
            dp[i+1][1] = (dp[i+1][1] + dp[i][j]) % MOD;
            dp[i+1][2] = (dp[i+1][2] + dp[i][j]) % MOD;
            dp[i+1][6] = (dp[i+1][6] + dp[i][j]) % MOD;
          }
          break;
        case 4:
          if (s[i+1] > 0) {
            if (s[i+1] != 1) dp[i+1][s[i+1]] = (dp[i+1][s[i+1]] + dp[i][j]) % MOD;
          } else {
            dp[i+1][2] = (dp[i+1][2] + dp[i][j]) % MOD;
            dp[i+1][3] = (dp[i+1][3] + dp[i][j]) % MOD;
          }
          break;
        case 5:
          if (s[i+1] > 0) {
            if (s[i+1] != 2) dp[i+1][s[i+1]] = (dp[i+1][s[i+1]] + dp[i][j]) % MOD;
          } else {
            dp[i+1][1] = (dp[i+1][1] + dp[i][j]) % MOD;
            dp[i+1][3] = (dp[i+1][3] + dp[i][j]) % MOD;
          }
          break;
        case 6:
          if (s[i+1] > 0) {
            if (s[i+1] != 3) dp[i+1][s[i+1]] = (dp[i+1][s[i+1]] + dp[i][j]) % MOD;
          } else {
            dp[i+1][1] = (dp[i+1][1] + dp[i][j]) % MOD;
            dp[i+1][2] = (dp[i+1][2] + dp[i][j]) % MOD;
          }
          break;
      }
    }
  }
  int res = 0;
  for (int j = 1; j <= 6; ++j) {
    res = (res + dp[n][j]) % MOD;
  }
  cout << res << endl;
  return 0;
}
