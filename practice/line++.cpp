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

// https://atcoder.jp/contests/abc160/tasks/abc160_d

void bfs(const vector<vector<int>>& graph, vector<int>& ans, set<pi> s, int start, int n) {
  vector<int> dist(n, INF);
  queue<int> que;
  que.emplace(start);
  dist[start] = 0;
  while (!que.empty()) {
    int current = que.front(); que.pop();
    for (auto next : graph[current]) {
      if (dist[next] != INF) continue;
      que.emplace(next);
      dist[next] = dist[current] + 1;
    }
  }
  rep (i, n) if (i != start) {
    int first = min(i, start);
    int second = max(i, start);
    if (s.find(pi(first, second)) == s.end()) {
      s.emplace(pi(first, second));
      ++ans[dist[i]];
    }
  }
}

int main() {
  int n, x, y; cin >> n >> x >> y; --x, --y;
  vector<vector<int>> graph(n);
  rep (i, n - 1) {
    graph[i].emplace_back(i + 1);
    graph[i+1].emplace_back(i);
  }
  graph[x].emplace_back(y);
  graph[y].emplace_back(x);
  vector<int> ans(n);
  set<pi> s;
  rep (i, n) bfs(graph, ans, s, i, n);
  reps (i, 1, n) cout << ans[i] / 2 << endl;
  return 0;
}