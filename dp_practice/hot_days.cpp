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

// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d

int main() {
  int d, n;
  cin >> d >> n;
  vector<int> T(d);
  vector<int> A(n), B(n), C(n);
  vector<vector<int>> dp(d, vector<int>(n, -1));
  rep (i, d) cin >> T[i];
  rep (i, n) {
    cin >> A[i] >> B[i] >> C[i];
    if (A[i] <= T[0] && T[0] <= B[i]) dp[0][i] = 0;
  }
  for (int i = 1; i < d; ++i) {
    for (int j = 0; j < n; ++j) {
      if (A[j] > T[i] || T[i] > B[j]) continue;
      for (int k = 0; k < n; ++k) {
        if (dp[i-1][k] == -1) continue;
        dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(C[j] - C[k]));
      }
    }
  }
  int res = 0;
  rep (i, n) res = max(res, dp[d-1][i]);
  cout << res << endl;
  return 0;
}
