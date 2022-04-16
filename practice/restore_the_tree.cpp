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

// https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d

int main() {
  int n, m; cin >> n >> m;
  TsGraph ts(n);
  vector<vector<int>> graph(n);
  rep (i, n - 1 + m) {
    int a, b; cin >> a >> b; --a, --b;
    ts.add_edge(a, b);
    graph[a].emplace_back(b);
  }
  vector<int> tsGraph = ts.topological_sort();
  vector<int> depth(n);
  rep (i, n) {
    for (auto next : graph[tsGraph[i]]) {
      depth[next] = max(depth[next], depth[tsGraph[i]] + 1);
    }
  }
  vector<int> ans(n, -1);
  rep (i, n) {
    for (auto next : graph[i]) if (depth[next] - depth[i] == 1) ans[next] = i;
  }
  rep (i, n) cout << ans[i] + 1 << endl;
  return 0;
}