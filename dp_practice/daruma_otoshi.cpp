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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp

int main() {
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> blocks(n, 0);
    rep (i, n) cin >> blocks[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    rep (i, n-1) dp[i][i+1] = (abs(blocks[i] - blocks[i+1]) <= 1) ? 2 : 0;
    for (int i = 2; i < n; ++i) {
      for (int l = 0; l + i < n; ++l) {
        int r = l + i;
        if (dp[l+1][r-1] == (r - l - 1) && abs(blocks[l] - blocks[r]) <= 1) {
          dp[l][r] = dp[l+1][r-1] + 2;
          continue;
        }

        for (int mid = l; mid < r; ++mid) {
          dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid+1][r]);
        }
      }
    }
    cout << dp[0][n-1] << endl;
  }
  return 0;
}
