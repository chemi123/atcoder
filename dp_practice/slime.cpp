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

// https://atcoder.jp/contests/dp/tasks/dp_n

const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> slimes(n, 0);
  rep (i, n) cin >> slimes[i];
  vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, make_pair(1e15, 1e15)));
  rep (i, n) dp[i][i].first = 0, dp[i][i].second = slimes[i];
  rep (i, n-1) dp[i][i+1].first = slimes[i] + slimes[i+1], dp[i][i+1].second = slimes[i] + slimes[i+1];
  for (int k = 2; k < n; ++k) {
    for (int i = 0; i < n - k; ++i) {
      int j = i + k;
      for (int l = i; l < j; ++l) {
        ll cost = dp[i][l].second + dp[l+1][j].second;
        dp[i][j].first = min(dp[i][j].first, dp[i][l].first + dp[l+1][j].first + cost);
        dp[i][j].second = min(dp[i][j].second, cost);
      }
    }
  }
  cout << dp[0][n-1].first << endl;
  return 0;
}
