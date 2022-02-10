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

// https://atcoder.jp/contests/dp/tasks/dp_n

ll rec(const vector<ll>& a, const vector<ll>& acc, vector<vector<ll>>& dp, int l, int r) {
  if (l == r) return dp[l][r] = 0;
  if (dp[l][r] != -1) return dp[l][r];
  ll sum = acc[r];
  if (l > 0) sum -= acc[l-1];
  ll res = INFL;
  reps (mid, l, r) res = min(res, rec(a, acc, dp, l, mid) + rec(a, acc, dp, mid + 1, r) + sum);
  return dp[l][r] = res;
}

int main() {
  int n; cin >> n;
  vector<ll> a(n), acc(n);
  rep (i, n) {
    cin >> a[i];
    if (i == 0) acc[i] = a[i];
    else acc[i] = acc[i-1] + a[i];
  }
  vector dp(n, vector<ll>(n, -1));
  cout << rec(a, acc, dp, 0, n - 1) << endl;
  return 0;
}