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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> block(n, 0);
    rep (i, n) cin >> block[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    rep (i, n-1) dp[i][i+1] = (abs(block[i] - block[i+1]) <= 1) ? 2 : 0;
    reps (i, 2, n) {
      rep (l, n-i) {
        int r = l + i;
        if (abs(block[l] - block[r]) <= 1 && dp[l+1][r-1] == r - l - 1) {
          dp[l][r] = dp[l+1][r-1] + 2;
          continue;
        }
        rep (mid, r) {
          dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid+1][r]);
        }
      }
    }
    cout << dp[0][n-1] << endl;
  }
  return 0;
}
