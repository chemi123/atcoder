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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=ja

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> values(n, 0), weights(n, 0);
  rep (i, n) cin >> values[i] >> weights[i];
  vector<vector<int>> dp(n+ 1, vector<int>(w + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int weight = 0; weight <= w; ++weight) {
      if (weight >= weights[i]) dp[i+1][weight] = max(dp[i][weight-weights[i]] + values[i], dp[i][weight]);
      else dp[i+1][weight] = dp[i][weight];
    }
  }
  cout << dp[n][w] << endl;
  return 0;
} 