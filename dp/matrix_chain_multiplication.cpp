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
const ll MOD = 1000000007;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja

int main() {
  int n; cin >> n;
  vector<int> rows(n), cols(n);
  rep (i, n) cin >> rows[i] >> cols[i];
  vector dp(n, vector<int>(n, INF));
  rep (i, n) dp[i][i] = 0;
  rep (i, n - 1) dp[i][i+1] = rows[i] * rows[i+1] * cols[i+1];
  reps (i, 2, n) {
    rep (l, n - i) {
      int r = l + i;
      reps (mid, l, r) dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid+1][r] + rows[l] * rows[mid+1] * cols[r]);
    }
  }
  cout << dp[0].back() << endl;
  return 0;
}