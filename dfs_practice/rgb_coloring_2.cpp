#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
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

// https://atcoder.jp/contests/abc199/tasks/abc199_d

void dfs1(const vector<vector<int>>& graph, vector<int>& connected, vector<bool>& visit, int current) {
  if (visit[current]) return;
  visit[current] = true;
  connected.emplace_back(current);
  for (auto next : graph[current]) dfs1(graph, connected, visit, next);
}

void dfs2(const vector<vector<int>>& graph, const vector<int>& connected, vector<int>& color, int i, ll& total) {
  if (i == connected.size()) {
    ++total;
    return;
  }
  int current = connected[i];
  rep (c, 3) {
    color[current] = c;
    bool ok = true;
    for (auto neighbor : graph[current]) {
      if (color[neighbor] == c) ok = false;
    }
    if (ok) dfs2(graph, connected, color, i + 1, total);
  }
  color[current] = -1;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<bool> visit(n, false);
  ll ans = 1;
  rep (i, n) {
    if (visit[i]) continue;
    vector<int> connected;
    dfs1(graph, connected, visit, i);
    vector<int> color(n, -1);
    color[connected[0]] = 0;
    ll total = 0;
    dfs2(graph, connected, color, 1, total);
    ans *= (3 * total);
  }
  cout << ans << endl;
  return 0;
}