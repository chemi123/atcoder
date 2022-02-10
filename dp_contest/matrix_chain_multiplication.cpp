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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja

ll rec(const vector<ll>& row, const vector<ll>& col, vector<vector<ll>>& dp, int l, int r) {
  if (l == r) return dp[l][r] = 0;
  if (dp[l][r] != INFL) return dp[l][r];
  reps (mid, l, r) dp[l][r] = min(dp[l][r], rec(row, col, dp, l, mid) + rec(row, col, dp, mid + 1, r) + row[l] * row[mid+1] * col[r]);
  return dp[l][r];
}

int main() {
  int n; cin >> n;
  vector<ll> r(n), c(n);
  rep (i, n) cin >> r[i] >> c[i];
  vector dp(n, vector<ll>(n, INFL));
  cout << rec(r, c, dp, 0, n - 1) << endl;
  return 0;
}