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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199&lang=ja

int main() {
  while (1) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    vector<int> c(m, 0);
    vector<int> pulse(n, 0);
    rep (i, m) cin >> c[i];
    rep (i, n) cin >> pulse[i];
    vector<vector<int>> dp(n+1, vector<int>(256, 1e9));
    dp[0][128] = 0;
    rep (i, n) {
      rep (j, 256) {
        if (dp[i][j] == 1e9) continue;
        rep (k, m) {
          int ck = j + c[k];
          if (ck > 255) ck = 255;
          if (ck < 0) ck = 0;
          int diff = (pulse[i] - ck) * (pulse[i] - ck);
          dp[i+1][ck] = min(dp[i+1][ck], dp[i][j] + diff);
        }
      }
    }
    int res = 1e9;
    rep (i, 256) res = min(res, dp[n][i]);
    cout << res << endl;
  }
  return 0;
}
