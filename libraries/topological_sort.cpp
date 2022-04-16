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

// 0indexのグラフでで使用すること
class TsGraph {
public:
  TsGraph(int n) : _graph(vector<vector<int>>(n)), _n(n) {}
  
  void add_edge(int a, int b) { _graph[a].emplace_back(b); }

  vector<int> topological_sort() {
    vector<bool> visit(_n);
    vector<int> res;
    res.reserve(_n);
    for (int i = 0; i < _n; ++i) _dfs(res, visit, i);
    reverse(res.begin(), res.end());
    return res;
  }

private:
  void _dfs(vector<int>& v, vector<bool>& visit, int current) {
    if (visit[current]) return;
    visit[current] = true;
    for (auto next : _graph[current]) _dfs(v, visit, next);
    v.emplace_back(current);
  }

  int _n;
  vector<vector<int>> _graph;
};

// 以下で動作確認できている
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

int main() {
  int v, e; cin >> v >> e;
  TsGraph ts(v);
  rep (i, e) {
    int s, t; cin >> s >> t;
    ts.add_edge(s, t);
  }
  vector<int> ans = ts.topological_sort();
  for (auto e : ans) cout << e << endl;
  return 0;
}