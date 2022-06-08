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

// https://atcoder.jp/contests/abc254/tasks/abc254_e

int bfs(const vector<vector<int>>& graph, int x, int k) {
  unordered_map<int, int> visit;
  queue<int> que;
  visit.emplace(x, 0);
  que.emplace(x);
  ll res = x;
  while (!que.empty()) {
    int current = que.front(); que.pop();
    int current_step = visit[current];
    if (current_step + 1 > k) continue;
    for (auto next : graph[current]) {
      if (visit.find(next) != visit.end()) continue;
      res += next;
      visit.emplace(next, current_step + 1);
      que.emplace(next);
    }
  }
  return res;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  rep (i, m) {
    int a, b; cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  int q; cin >> q;
  while (q--) {
    int x, k; cin >> x >> k;
    cout << bfs(graph, x, k) << endl;
  }
  return 0;
}