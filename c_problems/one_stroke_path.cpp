#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
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

// https://atcoder.jp/contests/abc054/tasks/abc054_c

void dfs(const vector<vector<int>>& graph, unordered_set<int>& visit, int& ans, int current, int n) {
  if (visit.size() == n) {
    ++ans;
    return;
  }

  for (auto next : graph[current]) {
    if (visit.find(next) != visit.end()) continue;
    visit.emplace(next);
    dfs(graph, visit, ans, next, n);
    visit.erase(next);
  }
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  rep (i, m) {
    int a, b; cin >> a >> b; --a, --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  unordered_set<int> visit;
  visit.emplace(0);
  int ans = 0;
  dfs(graph, visit, ans, 0, n);
  cout << ans << endl;
  return 0;
}
