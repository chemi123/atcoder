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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp

int rec(const vector<int>& w, vector<vector<int>>& dp, int l, int r) {
  if (l == r) return dp[l][r] = 0;
  if (dp[l][r] != -1) return dp[l][r];
  reps (mid, l, r) dp[l][r] = max(dp[l][r], rec(w, dp, l, mid) + rec(w, dp, mid + 1, r));
  if (r - l == 1) {
    if (abs(w[l] - w[r]) <= 1) dp[l][r] = 2;
    return dp[l][r];
  }
  if (rec(w, dp, l + 1, r - 1) == r - l - 1 && abs(w[l] - w[r]) <= 1) dp[l][r] = r - l + 1;
  return dp[l][r];
}

int main() {
  while (1) {
    int n; cin >> n;
    if (n == 0) break;
    vector<int> w(n);
    rep (i, n) cin >> w[i];
    vector dp(n, vector<int>(n , -1));
    cout << rec(w, dp, 0, n - 1) << endl;
  }
  return 0;
}