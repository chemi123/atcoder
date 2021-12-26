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

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja

int main() {
  int n;
  cin >> n;
  rep (a, n) {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        if (s[i-1] == t[j-1]) dp[i][j] = max({dp[i][j], dp[i-1][j-1]+1});
      }
    }
    cout << dp[n][m] << endl;
  }
  return 0;
}
