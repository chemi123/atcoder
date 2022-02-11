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

// https://atcoder.jp/contests/tdpc/tasks/tdpc_iwi

int rec(const string& s, vector<vector<int>>& dp, int l, int r) {
  if (l == r) return dp[l][r] = 0;
  if (dp[l][r] != -1) return dp[l][r];

  reps (mid, l, r) dp[l][r] = max(dp[l][r], rec(s, dp, l, mid) + rec(s, dp, mid + 1, r));
  int w = r - l + 1;
  if (w % 3 != 0) return dp[l][r];
  if (s[l] != 'i' || s[r] != 'i') return dp[l][r];
  reps (i, l + 1, r) {
    if (s[i] != 'w') continue;
    if (i - l > 1 && rec(s, dp, l + 1, i - 1) != (i - l - 1)) continue;
    if (r - i > 1 && rec(s, dp, i + 1, r - 1) != (r - i - 1)) continue;
    dp[l][r] = max(dp[l][r], w);
  }
  return dp[l][r];
}

int main() {
  string s; cin >> s;
  int n = (int)s.size();
  vector dp(n, vector<int>(n, -1));
  cout << rec(s, dp, 0, n - 1) / 3 << endl;
  return 0;
}