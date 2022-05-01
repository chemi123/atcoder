#include <algorithm>
#include <bitset>
#include <cassert>
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

// https://atcoder.jp/contests/abc188/tasks/abc188_e

int main() {
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  vector<vector<int>> graph(n);
  rep (i, n) cin >> a[i];
  rep (i, m) {
    int x, y; cin >> x >> y; --x, --y;
    graph[x].emplace_back(y);
  }
  vector<ll> dp(n, INFL);
  rep (i, n) for (auto next : graph[i]) dp[next] = min(dp[next], min(a[i], dp[i]));
  ll ans = -INF;
  rep (i, n) ans = max(ans, a[i] - dp[i]);
  cout << ans << endl;
  return 0;
}