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

// https://atcoder.jp/contests/dp/tasks/dp_g

int dfs(const vector<vector<int>>& graph, vector<int>& dp, int current) {
  if (dp[current] > 0) return dp[current];
  int ans = 0;
  for (auto next : graph[current]) ans = max(ans, dfs(graph, dp, next) + 1); 
  return dp[current] = ans;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  rep (i, m) {
    int x, y; cin >> x >> y; --x, --y;
    graph[x].emplace_back(y);
  }
  vector<int> dp(n, -1);
  int ans = 0;
  rep (i, n) ans = max(ans, dfs(graph, dp, i));
  cout << ans << endl;
  return 0;
}