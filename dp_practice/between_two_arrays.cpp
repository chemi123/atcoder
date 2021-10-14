#include <algorithm>
#include <bitset>
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
const ll MOD = 998244353;

// 考え方はあっているはずだが、なぜか通らない...
// 正解コードとランダムテストケースを比較してもすべて結果は一致している。
// https://atcoder.jp/contests/abc222/tasks/abc222_d

int main() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];
  
  int maxNum = 3000;
  vector dp(n, vector<ll>(maxNum + 1));
  if (a[0] == 0) dp[0][0] = 1;
  reps (i, 1, 3001) {
    if (a[0] <= i && i <= b[0]) dp[0][i] = dp[0][i-1] + 1;
    else dp[0][i] = dp[0][i-1];
  }

  reps (i, 1, n) {
    reps (j, a[i], maxNum + 1) {
      if (j <= b[i]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
      else dp[i][j] = dp[i][j-1];
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}