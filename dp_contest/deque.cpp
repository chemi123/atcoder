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

// 結構難しい
// https://atcoder.jp/contests/dp/tasks/dp_l

ll rec(const vector<ll>& a, vector<vector<ll>>& dp, int l, int r, int n) {
  if (l == r) return dp[l][r] = 0;
  if (dp[l][r] != INF) return dp[l][r];
  if ((n - (r - l)) % 2 == 0) return dp[l][r] = max(rec(a, dp, l + 1, r, n) + a[l], rec(a, dp, l, r - 1, n) + a[r-1]);
  return dp[l][r] = min(rec(a, dp, l + 1, r, n) - a[l], rec(a, dp, l, r - 1, n) - a[r-1]);
}

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  vector dp(n + 1, vector<ll>(n + 1, INF));
  cout << rec(a, dp, 0, n, n) << endl;
  return 0;
}