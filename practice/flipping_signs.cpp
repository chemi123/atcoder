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

// https://atcoder.jp/contests/abc125/tasks/abc125_d

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep (i, n) cin >> a[i];
  vector dp(n - 1, vector<ll>(2));
  dp[0][0] = a[0] + a[1], dp[0][1] = -a[0] - a[1];
  reps (i, 1, n - 1) {
    dp[i][0] = max(dp[i-1][0] + a[i+1], dp[i-1][1] + a[i+1]);
    dp[i][1] = max(dp[i-1][0] - 2 * a[i] - a[i+1], dp[i-1][1] + 2 * a[i] - a[i+1]);
  }
  cout << max(dp.back()[0], dp.back()[1]) << endl;
  return 0;
}