#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1000000007;

// https://atcoder.jp/contests/abc248/tasks/abc248_f

void modAdd(ll& a, ll b, ll p) {
  a = (a + b) % p;
}

int main() {
  int n; cin >> n;
  ll p; cin >> p;
  vector dp(n + 5, vector<vector<ll>>(n + 5, vector<ll>(2)));
  dp[0][1][0] = 1;
  dp[0][0][1] = 1;
  reps (i, 1, n) {
    rep (j, n) {
      // 線を消さない　
      modAdd(dp[i][j][1], dp[i-1][j][1], p);
      modAdd(dp[i][j][1], dp[i-1][j][0], p);

      // 線を1本消す
      modAdd(dp[i][j+1][0], dp[i-1][j][0], p);
      modAdd(dp[i][j+1][1], dp[i-1][j][1], p); // ここが重要。平行に線をつなげるだけなので遷移後の上下の線はないが、以前に上下に連結されていたため遷移後も実質上下に連結していると見なすことができる
      modAdd(dp[i][j+1][1], dp[i-1][j][1], p);
      modAdd(dp[i][j+1][1], dp[i-1][j][1], p);

      // 線を2本消す
      modAdd(dp[i][j+2][0], dp[i-1][j][1], p);
      modAdd(dp[i][j+2][0], dp[i-1][j][1], p);
    }
  }
  reps (i, 1, n) cout << dp[n-1][i][1] << " "; cout << endl;
  return 0;
}