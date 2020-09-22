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

// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d

int main() {
  ll n, goal;
  cin >> n;
  vector<ll> nums(n);
  rep (i, n-1) cin >> nums[i]; cin >> goal;
  vector<vector<ll>> dp(n-1, vector<ll>(21));
  dp[0][nums[0]] = 1;
  for (int i = 1; i < n-1; ++i) {
    for (int j = 0; j <= 20; ++j) {
      if (dp[i-1][j] == 0) continue;
      if (nums[i] <= j) dp[i][j-nums[i]] += dp[i-1][j];
      if (nums[i] + j <= 20) dp[i][j+nums[i]] += dp[i-1][j];
    }
  }
  cout << dp[n-2][goal] << endl;
  return 0;
}
