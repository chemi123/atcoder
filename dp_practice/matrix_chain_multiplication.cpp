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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja

int main() {
  int n;
  cin >> n;
  vector<int> r(n+1, 0);
  rep (i, n) cin >> r[i] >> r[i+1];
  vector<vector<int>> dp(n, vector<int>(n, 1e9));
  rep (i, n) dp[i][i] = 0;
  rep (i, n-1) dp[i][i+1] = r[i] * r[i+1] * r[i+2];
  for (int i = 2; i < n; ++i) {
    for (int j = 0; j < n - i; ++j) {
      for (int k = j; k < i + j; ++k) {
        dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + r[j] * r[k+1] * r[i+j+1]);
      }
    }
  }
  cout << dp[0][n-1] << endl;
  return 0;
}
