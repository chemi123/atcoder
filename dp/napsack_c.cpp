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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=ja#

int main() {
  int n, capacity;
  cin >> n >> capacity;
  vector<int> values(n, 0), weights(n, 0);
  rep (i, n) cin >> values[i] >> weights[i];
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= capacity; ++w) {
      if (w >= weights[i]) dp[i+1][w] = max({dp[i][w-weights[i]] + values[i], dp[i][w], dp[i+1][w-weights[i]] + values[i]});
      else dp[i+1][w] = dp[i][w];
    }
  }
  cout << dp[n][capacity] << endl;
  return 0;
}
