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
  vector<int> rows(n, 0), cols(n, 0);
  rep (i, n) cin >> rows[i] >> cols[i];
  vector<vector<int>> dp(n, vector<int>(n, 1e9));
  rep (i, n) dp[i][i] = 0;
  rep (i, n-1) dp[i][i+1] = rows[i] * cols[i] * cols[i+1];
  for (int i = 2; i < n; ++i) {
    for (int l = 0; l < n - i; ++l) {
      int r = l + i;
      for (int mid = l; mid < r; ++mid) {
        dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid+1][r] + rows[l] * rows[mid+1] * cols[r]);
      }
    }
  }
  cout << dp[0][n-1] << endl;
  return 0;
}
