#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
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

// https://atcoder.jp/contests/abc087/tasks/arc090_a

int main() {
  int n; cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep (i, 2) rep (j, n) cin >> a[i][j];
  vector<vector<int>> dp(2, vector<int>(n));
  dp[0][0] = a[0][0];
  reps (i, 1, n) dp[0][i] = dp[0][i-1] + a[0][i];
  dp[1][0] = dp[0][0] + a[1][0];
  reps (i, 1, n) dp[1][i] = max(dp[0][i] + a[1][i], dp[1][i-1] + a[1][i]);
  cout << dp[1].back() << endl;
  return 0;
}