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

// https://atcoder.jp/contests/abc239/tasks/abc239_e

void dfs(const vector<vector<int>>& graph, vector<vector<int>>& ans, const vector<int>& x, int current, int parent) {
  vector<int> res{x[current]};
  for (auto next : graph[current]) if (next != parent) {
    dfs(graph, ans, x, next, current);
    res.reserve(res.size() + ans[next].size());
    copy(ans[next].begin(), ans[next].end(), back_inserter(res));
    sort(res.begin(), res.end(), greater<int>());
    if ((int)res.size() > 20) res.resize(20);
  }
  ans[current] = res;
}

int main() {
  int n, q; cin >> n >> q;
  vector<int> x(n);
  rep (i, n) cin >> x[i];
  vector<vector<int>> graph(n);
  rep (i, n - 1) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<vector<int>> ans(n);
  dfs(graph, ans, x, 0, -1);
  rep (i, q) {
    int v, k; cin >> v >> k; --v, --k;
    cout << ans[v][k] << endl;
  }
  return 0;
}