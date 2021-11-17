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

// https://atcoder.jp/contests/typical90/tasks/typical90_s

int main() {
  int n; cin >> n;
  vector<int> a(2 * n);
  rep (i, 2 * n) cin >> a[i];
  vector dp(2 * n, vector<int>(2 * n, INF));
  rep (i, 2 * n - 1) dp[i][i+1] = abs(a[i] - a[i+1]);
  for (int i = 3; i < 2 * n; i += 2) {
    for (int l = 0; l < 2 * n - i; ++l) {
      int r = l + i;
      reps (mid, l, r) dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid+1][r]);
      dp[l][r] = min(dp[l][r], abs(a[l] - a[r]) + dp[l+1][r-1]);
    }
  }
  cout << dp[0].back() << endl;
  return 0;
}