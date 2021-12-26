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

// https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b

/*
  初めて取り組んだ時に相当苦労した。ここを参考にした。
  https://toonanote.com/joi-2015-%e6%9c%ac%e9%81%b8-2-%e3%82%b1%e3%83%bc%e3%82%ad%e3%81%ae%e5%88%87%e3%82%8a%e5%88%86%e3%81%91-2/
*/

int main() {
  int n;
  cin >> n;
  vector<ll> pc(n, 0);
  rep (i, n) cin >> pc[i];
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  if (n % 2 == 1) {
    rep (i, n) dp[i][(i+1) % n] = pc[i];
  }
  // 残りが一個の時はdp[i][(i+1)%n]で初期化できているため、残りが2個からn個までで行う
  for (int remain = 2; remain <= n; ++remain) {
    for (int l = 0; l < n; ++l) {
      int r = l + remain;
      // nのmodを取っているのは円環なので、範囲を超えた場合でも対応できるようにするため。
      if (remain % 2 == n % 2) /* JOIのターン */ {
        dp[l][r%n] = max(dp[l][(r-1)%n] + pc[(r-1)%n], dp[(l+1)%n][r%n] + pc[l]);
      } else {
        if (pc[(r-1)%n] > pc[l]) {
          dp[l][r%n] = dp[l][(r-1)%n];
        } else {
          dp[l][r%n] = dp[(l+1)%n][r%n];
        }
      }
    }
  }
  ll ans = 0;
  rep (i, n) ans = max(ans, dp[i][i]);
  cout << ans << endl;

  return 0;
}
