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
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g

int main() {
  ll n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << "1 0" << endl;
    return 0;
  }
  vector<vector<ll>> cost(n, vector<ll>(n, -1)), timeLimits(n, vector<ll>(n, -1));
  rep (i, m) {
    ll s, t, distance, timeLimit;
    cin >> s >> t >> distance >> timeLimit;
    --s, --t;
    cost[s][t] = distance, cost[t][s] = distance;
    timeLimits[s][t] = timeLimit, timeLimits[t][s] = timeLimit;
  }
  vector<vector<ll>> dp(1 << n, vector<ll>(n, 1e15)), cnt(1 << n, vector<ll>(n, 0));
  dp[0][0] = 0, cnt[0][0] = 1;
  for (ll S = 0; S < (1 << n); ++S) {
    for (ll from = 0; from < n; ++from) {
      for (ll to = 0; to < n; ++to) {
        if ((S >> to & 1) == 0 && cost[from][to] != -1 && dp[S][from] + cost[from][to] <= timeLimits[from][to]) {
          if (dp[S | 1 << to][to] > dp[S][from] + cost[from][to]) {
            dp[S | 1 << to][to] = dp[S][from] + cost[from][to];
            cnt[S | 1 << to][to] = cnt[S][from];
          } else if (dp[S | 1 << to][to] == dp[S][from] + cost[from][to]) {
            cnt[S | 1 << to][to] += cnt[S][from];
          }
        }
      }
    }
  }
  dp[(1 << n) - 1][0] == 1e15 ? cout << "IMPOSSIBLE" : cout << dp[(1 << n) - 1][0] << " " << cnt[(1 << n) - 1][0];
  cout << endl;
  return 0;
}
