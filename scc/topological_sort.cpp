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

// 強連結成分(scc: strongly connected component)と似ていると思ったためsccフォルダに置いておく
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja

void dfs(const vector<vector<int>>& graph, vector<int>& ans, vector<bool>& visit, int current) {
  if (visit[current]) return;
  visit[current] = true;

  for (auto next : graph[current]) dfs(graph, ans, visit, next);
  ans.emplace_back(current);
}

int main() {
  int v, e; cin >> v >> e;
  vector<vector<int>> graph(v);
  rep (i, e) {
    int s, t; cin >> s >> t;
    graph[s].emplace_back(t);
  }

  vector<int> ans;
  ans.reserve(v);
  vector<bool> visit(v);
  rep (i, v) dfs(graph, ans, visit, i);
  reverse(ans.begin(), ans.end());
  for (auto e : ans) cout << e << endl;
  return 0;
}